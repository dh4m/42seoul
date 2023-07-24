/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:23:26 by dham              #+#    #+#             */
/*   Updated: 2023/07/24 17:53:04 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operator.hpp"

Operator::Operator(ClientInfo &info, std::string passwd)
: _info(info), _passwd(passwd)
{}

Operator::~Operator(void)
{}

int Operator::cmd_proc(const std::string &cmd_str, ClientRef sender)
{
	int res = 0;
	int sender_del = 0;

	_cmd_idx = 0;
	_cmd_str = cmd_str;
	_sender = sender;
	_argu.clear();

	if (!_parsing_msg())
	{
		return (1); // unknown cmd
	}
	switch (_command)
	{
	case CMD_PASS:
		res = _pass();
		break;
	case CMD_NICK:
		res = _nick();
		break;
	case CMD_USER:
		res = _user();
		break;
	case CMD_JOIN:
		res = _join();
		break;
	case CMD_PRIVMSG:
		res = _privmsg();
		break;
	case CMD_NOTICE:
		res = _notice();
		break;
	case CMD_OPER:
		res = _oper();
		break;
	case CMD_KICK:
		res = _kick();
		break;
	case CMD_INVITE:
		res = _invite();
		break;
	case CMD_MODE:
		res = _mode();
		break;
	case CMD_TOPIC:
		res = _topic();
		break;
	case CMD_QUIT:
		res = _quit();
		break;
	case CMD_PART:
		res = _part();
		break;
	case CMD_PING:
		res = _ping();
		break;
	case UNKNOWN:
		break;
	default:
		break;
	}
	if (sender_del)
		return (0);
	return (1);
}

int Operator::_parsing_msg(void)
{
	if (_cmd_str[0] == ':')
	{
		if (!_prefix_setting()) // prefix
			return (0); // unavailable prefix
	}
	if (_cmd_setting() == UNKNOWN) // command setting
	{
		return (0); // unknown cmd
	}
	_argu_setting(); // npos 내부에서 확인할 것
	return (1);
}

int Operator::_prefix_setting(void)
{
	_cmd_idx = _cmd_str.find(SPACE);
	if (_cmd_idx == std::string::npos || _cmd_idx == 1)
		return (0); // unavailable prefix
	_prefix = _cmd_str.substr(1, _cmd_idx - 1);
	while (_cmd_idx < _cmd_length && _cmd_str[_cmd_idx] == SPACE)
		_cmd_idx++;
	return (1);
}

int Operator::_cmd_setting(void)
{
	size_t cmd_len = _cmd_str.find(SPACE, _cmd_idx) - _cmd_idx;
	std::string _command_str = _cmd_str.substr(_cmd_idx, cmd_len);

	if (_command_str == "PASS")
		_command = CMD_PASS;
	else if (_command_str == "NICK")
		_command = CMD_NICK;
	else if (_command_str == "USER")
		_command = CMD_USER;
	else if (_command_str == "JOIN")
		_command = CMD_JOIN;
	else if (_command_str == "PRIVMSG")
		_command = CMD_PRIVMSG;
	else if (_command_str == "NOTICE")
		_command = CMD_NOTICE;
	else if (_command_str == "OPER")
		_command = CMD_OPER;
	else if (_command_str == "KICK")
		_command = CMD_KICK;
	else if (_command_str == "INVITE")
		_command = CMD_INVITE;
	else if (_command_str == "MODE")
		_command = CMD_MODE;
	else if (_command_str == "TOPIC")
		_command = CMD_TOPIC;
	else if (_command_str == "QUIT")
		_command = CMD_QUIT;
	else if (_command_str == "PART")
		_command = CMD_PART;
	else if (_command_str == "PING")
		_command = CMD_PING;
	else
		_command = UNKNOWN;

	_cmd_idx = _cmd_idx + cmd_len;
	if (_cmd_idx != std::string::npos)
	{
		while (_cmd_idx < _cmd_length && _cmd_str[_cmd_idx] == SPACE)
			_cmd_idx++;
	}
	return (_command);
}

void Operator::_argu_setting(void)
{
	while (_cmd_idx != std::string::npos)
	{
		if (_cmd_str[_cmd_idx] == ':')
		{
			std::string cmd = _cmd_str.substr(_cmd_idx);
			_argu.push_back(cmd);
			_cmd_idx = std::string::npos;
		}
		else
		{
			size_t cmd_len = _cmd_str.find(SPACE, _cmd_idx) - _cmd_idx;
			std::string cmd = _cmd_str.substr(_cmd_idx, cmd_len);
			_argu.push_back(cmd);
			_cmd_idx = _cmd_idx + cmd_len;
			if (_cmd_idx != std::string::npos)
			{
				while (_cmd_idx < _cmd_length && _cmd_str[_cmd_idx] == SPACE)
					_cmd_idx++;
			}
		}
	}
}

int Operator::_pass(void)
{
	/*
	if ((*_sender).avail_client() == NEEDPASS)
	{
		_reply_send(ERR_ALREADYRGISTRED, ""); // ERR_ALREADYRGISTRED
		return (0);
	}
	if (_argu.empty())
	{
		_reply_send(ERR_NEEDMOREPARAMS, ""); // ERR_NEEDMOREPARAMS
		_info.remove_client(_sender->get_fd(), "");
		return (0);
	}
	if (_argu[0] != _passwd)
	{
		_reply_send(ERR_PASSWDMISMATCH, ""); // ERR_PASSWDMISMATCH
		_info.remove_client(_sender->get_fd(), "");
		return (0);
	}
	*/
	_sender->pass_set(_argu[0]);
	return (1);
}

int Operator::_avail_nick(void)
{
	std::string nick = _argu[0];
	size_t nick_len = nick.length();
	int idx = 0;

	if (!isalpha(nick[0]))
		return (0);
	for (int i = 0; i < nick_len; i++)
	{
		if (!isalpha(nick[i]) && !isdigit(nick[i]) && nick[i] != '-' \
			&& nick[i] != '[' && nick[i] != ']' && nick[i] != '\\' && nick[i] != '`' \
			&& nick[i] != '^' && nick[i] != '{' && nick[i] != '}')
			return (0);
	}
	return (1);
}

int Operator::_nick(void)
{
	if (_sender->avail_client() == NEEDPASS)
	{
		;
		return (0);
	}
	if (!_avail_nick())
	{
		;
		return (0);
	}
	//
	//
	//
	_sender->nick_set(_argu[0]);
}

int Operator::_user(void)
{
	if (_sender->avail_client() == NEEDPASS)
	{
		;
		return (0);
	}
	///////
	///////
	_argu[3].erase(0, 1); // :삭제
	_sender->user_init(_argu[0], _argu[1], _argu[3]);
}

int Operator::_join(void)
{
	if (_argu.size() == 0)
	{
		_reply_send(ERR_NEEDMOREPARAMS, "");
		return (0);
	}

	int res;
	std::stringstream chan_list(_argu[0]);
	std::stringstream key_list;
	if (_argu.size() == 2)
		key_list << _argu[1];
	else
		key_list.clear();
	std::string chan, key;
	std::getline(chan_list, chan, ',');
	std::getline(key_list, key, ',');
	while (chan_list)
	{
		res = _info.join_chan(chan, key, _sender);
		if (res != 0 && res != -1) // join 안에서 에러 처리
		{
			_reply_send(res, chan); // join실패
		}
		else
		{
			Channel *join_chan = _info.find_chan(chan);
			std::string topic = join_chan->get_topic();
			if (topic.empty())
				_reply_send(RPL_NOTOPIC);
			else
				_reply_send(RPL_TOPIC);
			_reply_send(RPL_NAMREPLY);
			_reply_send(RPL_ENDOFNAMES);
		}
		std::getline(chan_list, chan, ',');
		if (key_list)
			std::getline(key_list, key, ',');
		else
			key = "";
	}
	return (1);
}

int Operator::_privmsg(void)
{
	if (_argu.size() < 2)
	{
		if (_argu.size() == 0 || _argu[0][0] == ':')
		{
			_reply_send(ERR_NORECIPIENT);
		}
		else
		{
			_reply_send(ERR_NOTEXTTOSEND);
		}
		return (0);
	}
	std::stringstream send_msgstream;
	//prefix
	send_msgstream << _sender->get_prifix() << " ";
	//cmd
	send_msgstream << "PRIVMSG" << " ";
	std::string send_msg = send_msgstream.str();
	
	std::stringstream recv_list(_argu[0]);
	std::string recv;
	std::string full_msg;
	std::getline(recv_list, recv, ',');
	while (recv_list)
	{
		full_msg = send_msg + recv + " :" + _argu[1];
		if (recv[0] == '#')
		{
			if (_sender->include_chan(recv))
			{
				Channel *recv_chan = _info.find_chan(recv);
				if (recv_chan)
					recv_chan->channel_output(full_msg, _sender->get_fd());
				else
					_reply_send(ERR_CANNOTSENDTOCHAN);
			}
			else
			{
				_reply_send(ERR_CANNOTSENDTOCHAN);
			}
		}
		else
		{
			ClientRef recv_cl = _info.find_client(recv); // user send
			if (!recv_cl)
			{
				_reply_send(ERR_NOSUCHNICK);// 유저 없음
			}
			else
				recv_cl->add_output(full_msg);
		}
		std::getline(recv_list, recv, ',');
	}
	return (1);
}

int Operator::_notice(void)
{
	; // privmsg 완성시 그것과 동일하게 복붙 후 메시지만 변경
}

int Operator::_oper(void)
{
	if (_argu.size() < 2)
	{
		_reply_send(ERR_NEEDMOREPARAMS);
		return (0);
	}
	if (_argu[0] != OPER_NAME)
	{
		_reply_send(ERR_NOOPERHOST);
	}
	if (_argu[1] != OPER_PASSWD)
	{
		_reply_send(ERR_PASSWDMISMATCH);
	}
	_sender->set_user_state(OPERATOR);
	_reply_send(RPL_YOUREOPER);
}

int Operator::_kick(void)
{
	if (_argu.size() < 2)
	{
		_reply_send(ERR_NEEDMOREPARAMS);
		return (0);
	}
	Channel *kick_chan = _info.find_chan(_argu[0]);
	if (!kick_chan)
	{
		_reply_send(ERR_NOSUCHCHANNEL);
		return (0);
	}
	if (_sender->include_chan(_argu[0]))
	{
		if (kick_chan->is_operator(_sender) || _sender->avail_client() == OPERATOR)
		{
			; ///// kick 수행
		}
		else
		{
			_reply_send(ERR_CHANOPRIVSNEEDED);
			return (0);
		}
	}
	else
	{
		_reply_send(ERR_NOTONCHANNEL);
		return (0);
	}
}

int Operator::_invite(void)
{
	if (_argu.size() < 2)
	{
		_reply_send(ERR_NEEDMOREPARAMS);
		return (0);
	}
	ClientRef invite_cl = _info.find_client(_argu[0]);
	if (!invite_cl)
	{
		_reply_send(ERR_NOSUCHNICK);
		return (0);
	}
	if (!_sender->include_chan(_argu[1]))
	{
		_reply_send(ERR_NOTONCHANNEL);
		return (0);
	}
	if (invite_cl->include_chan(_argu[1]))
	{
		_reply_send(ERR_USERONCHANNEL);
		return (0);
	}
	Channel *invite_chan = _info.find_chan(_argu[1]);
	if (!invite_chan->is_operator(_sender))
	{
		_reply_send(ERR_CHANOPRIVSNEEDED);
		return (0);
	}
	invite_chan->add_invite(_argu[0]);
	std::stringstream send_msg;
	send_msg << _sender->get_prifix() << " INVITE " << _argu[0] << " " << _argu[1];
	std::string invite_msg = send_msg.str();
	invite_cl->add_output(invite_msg);
	_reply_send(RPL_INVITING);
	return (1);
}

int Operator::_mode(void)
{
	;
}

int Operator::_topic(void)
{
	;
}

int Operator::_quit(void)
{
	//////
	//////
	///_sender->leave_all_channel(); 이거 clientinfo에서 처리해야 할 듯
	_info.remove_client(_sender->get_fd(), "");
}

int Operator::_part(void)
{
	//////
	//////
	std::stringstream chan(_argu[0]);
	std::string leave;
	std::getline(chan, leave, ',');
	while (chan)
	{
		if (_sender->include_chan(leave))
		{
			_info.leave_chan(leave, _sender);
		}
		else
		{
			
		}
		std::getline(chan, leave, ',');
	}
	///part 명령어로 응답?
	return (1);
}

int Operator::_ping(void) // good
{
	std::string pong_msg = ":";
	
	pong_msg += SERVER_NAME;
	pong_msg += " PONG ";
	pong_msg += SERVER_NAME;
	if (!_argu.empty())
	{
		pong_msg += " ";
		pong_msg += _argu[0];
	}
	_sender->add_output(pong_msg);
	return (1);
}

int Operator::_reply_send(int reply, std::string param)
{
	std::stringstream cmd;

	cmd << ":" << SERVER_NAME << " ";
	switch (reply)
	{
	case ERR_ALREADYRGISTRED:
		cmd << "462 " << _sender->get_nick() << " :You may not reregister";
		break;
	case ERR_NEEDMOREPARAMS:
		cmd << "461 " << _sender->get_nick() << " " << _command_str \
			<< " :Not enough parameters";
		break;
	case ERR_PASSWDMISMATCH:
		cmd << "464 " << _sender->get_nick() << " :Password incorrect";
		break;
	case ERR_NICKNAMEINUSE:
		cmd << "433 " << _sender->get_nick() << " " << param \
			<< " :Nickname is already in use.";
		break;
	case ERR_ERRONEUSNICKNAME:
		cmd << "432 " << _sender->get_nick() << " " << param \
			<< " :Erroneus nickname";
		break;
	case ERR_NONICKNAMEGIVEN:
		cmd << "431 " << _sender->get_nick() << " :No nickname given";
		break;
	case ERR_INVITEONLYCHAN:
		cmd << "473 " << _sender->get_nick() << " " << param \
			<< " :Cannot join channel (+i)";
		break;
	case ERR_BADCHANNELKEY:
		cmd << "475 " << _sender->get_nick() << " " << param \
			<< " :Cannot join channel (+k)";
		break;
	case ERR_CHANNELISFULL:
		cmd << "471 " << _sender->get_nick() << " " << param \
			<< " :Cannot join channel (+l)";
		break;
	case ERR_NOSUCHCHANNEL:
		cmd << "403 " << _sender->get_nick() << " " << param \
			<< " :No such channel";
		break;
	case ERR_NORECIPIENT:
		cmd << "411 " << _sender->get_nick() 
			<< " :No recipient given (" << param << ")";
		break;
	case ERR_CANNOTSENDTOCHAN:
		cmd << "404 " << _sender->get_nick() << " " << param \
			<< " :Cannot send to channel";
		break;
	case ERR_NOSUCHNICK:
		cmd << "401 " << _sender->get_nick() << " " << param \
			<< " :No such nick/channel";
		break;
	case ERR_NOTEXTTOSEND:
		cmd << "412 " << _sender->get_nick() << " :No text to send";
		break;
	case ERR_NOOPERHOST:
		cmd << "491 " << _sender->get_nick() << " :No O-lines for your host";
		break;
	case ERR_NOTONCHANNEL:
		cmd << "442 " << _sender->get_nick() << " " << param \
			<< " :You're not on that channel";
		break;
	case ERR_CHANOPRIVSNEEDED:
		cmd << "482 " << _sender->get_nick() << " " << param \
			<< " :You're not channel operator";
		break;
	case ERR_USERONCHANNEL:
		cmd << "443 " << _sender->get_nick() << " " << param \
			<< " :is already on channel";
		break;
	case ERR_UNKNOWNMODE:
		cmd << "472 " << _sender->get_nick() << " " << param \
			<< " :is unknown mode char to me";
		break;
	case ERR_USERSDONTMATCH:
		cmd << "502 " << _sender->get_nick() << " :Cant change mode for other users";
		break;
	case ERR_UMODEUNKNOWNFLAG:
		cmd << "501 " << _sender->get_nick() << " :Unknown MODE flag";
		break;

	case RPL_WELCOME:
		cmd << "001 " << _sender->get_nick() << " :Welcome to the 42_IRC Network, " << param;
		break;
	case RPL_TOPIC:
		cmd << "332 " << _sender->get_nick() << " " << param;
		break;
	case RPL_NAMREPLY:
		cmd << "353 " << _sender->get_nick() << " = " << param;
		break;
	case RPL_ENDOFNAMES:
		cmd << "366 " << _sender->get_nick() << " " << param << " :End of /NAMES list";
		break;
	case RPL_YOUREOPER:
		cmd << "381 " << _sender->get_nick() << " :You are now an IRC operator";
		break;
	case RPL_NOTOPIC:
		cmd << "331 " << _sender->get_nick() << " " << param << " :No topic is set";
		break;
	case RPL_INVITING:
		cmd << "341 " << _sender->get_nick() << " " << param; // doc 참조
		break;
	case RPL_CHANNELMODEIS:
		cmd << "324 " << _sender->get_nick() << " " << param; // doc 참조
		break;
	case RPL_UMODEIS:
		cmd << "221 " << _sender->get_nick() << " " << param;
		break;
	default:
		return (0);
	}
	std::string reply_str = cmd.str();
	_sender->add_output(reply_str);
	return (1);
}