/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:23:26 by dham              #+#    #+#             */
/*   Updated: 2023/07/17 19:59:37 by dham             ###   ########.fr       */
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

	_cmd_idx = 0;
	_cmd_str = cmd_str;
	_sender = sender;
	_argu.clear();

	if (!_parsing_msg())
	{
		return (0); // unknown cmd
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
	std::string cmd = _cmd_str.substr(_cmd_idx, cmd_len);

	if (cmd == "PASS")
		_command = CMD_PASS;
	else if (cmd == "NICK")
		_command = CMD_NICK;
	else if (cmd == "USER")
		_command = CMD_USER;
	else if (cmd == "JOIN")
		_command = CMD_JOIN;
	else if (cmd == "PRIVMSG")
		_command = CMD_PRIVMSG;
	else if (cmd == "NOTICE")
		_command = CMD_NOTICE;
	else if (cmd == "OPER")
		_command = CMD_OPER;
	else if (cmd == "KICK")
		_command = CMD_KICK;
	else if (cmd == "INVITE")
		_command = CMD_INVITE;
	else if (cmd == "MODE")
		_command = CMD_MODE;
	else if (cmd == "TOPIC")
		_command = CMD_TOPIC;
	else if (cmd == "QUIT")
		_command = CMD_QUIT;
	else if (cmd == "PART")
		_command = CMD_PART;
	else if (cmd == "PING")
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
			std::string cmd = _cmd_str.substr(_cmd_idx + 1);
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
	if ((*_sender).avail_client() != NEEDPASS)
	{
		; // ERR_ALREADYRGISTRED
		return (0);
	}
	if (_argu.empty())
	{
		; // ERR_NEEDMOREPARAMS
		// 클라이언트 제거
		return (0);
	}
	if (_argu[0] != _passwd)
	{
		; // ERR_PASSWDMISMATCH
		// 클라이언트 제거
		return (0);
	}
	_sender->pass_client();
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
	_sender->user_init(_argu[0], _argu[1]);
}

int Operator::_join(void)
{
	//////
	/////////
	if (!_info.join_chan(_argu[0], _argu[1], _sender))
	{
		; // join실패
		return (0);
	}
	else
	{
		; // join 성공
	}
	return (1);
}

int Operator::_privmsg(void)
{
	//////
	//////
	std::stringstream send_msgstream;
	//prefix
	send_msgstream << ":" << _sender->get_nick() << "!" << _sender->get_user()
				<< "@" << _sender->get_host() << " ";
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
				recv_chan->channel_output(full_msg, _sender->get_fd());
			}
			else
			{
				;// ERR_CANNOTSENDTOCHAN
			}
		}
		else
		{
			ClientRef recv_cl = _info.find_client(recv); // user send
			if (!recv_cl)
			{
				;// 유저 없음
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
	//////
	//////
	//////
	if (_argu[0] != OPER_NAME || _argu[1] != OPER_PASSWD)
	{
		; // 넌 나가라
	}
	_sender->set_user_state(OPERATOR);
}

int Operator::_kick(void)
{
	////
	////
	//////only operator
	;
}

int Operator::_invite(void)
{
	;
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
		pong_msg += " :";
		pong_msg += _argu[0];
	}
	_sender->add_output(pong_msg);
	return (1);
}

std::string Operator::_reply_make(int reply)
{
	switch (reply)
	{
	case ERR_ALREADYRGISTRED:
		/* code */
		break;
	
	default:
		break;
	}
}