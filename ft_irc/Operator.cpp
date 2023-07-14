/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:23:26 by dham              #+#    #+#             */
/*   Updated: 2023/07/14 19:55:23 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operator.hpp"

Operator::Operator(ClientInfo &info)
: _info(info)
{

}

Operator::~Operator(void)
{

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
	if (_cmd_idx == std::string::npos)
		return (0); // unavailable prefix
	_prefix = _cmd_str.substr(1, _cmd_idx - 1);
	while (_cmd_str[_cmd_idx] == SPACE)
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
	else if (cmd == "KILL")
		_command = CMD_KILL;
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
	else
		_command = UNKNOWN;

	_cmd_idx = _cmd_idx + cmd_len + 1;
	return (_command);
}

void Operator::_argu_setting(void)
{
	_argu_idx = 0;

	while (_cmd_idx != std::string::npos)
	{
		size_t cmd_len = _cmd_str.find(SPACE, _cmd_idx + 1) - (_cmd_idx + 1);
		std::string cmd = _cmd_str.substr(_cmd_idx + 1, cmd_len);

		
		_cmd_idx = _cmd_idx + cmd_len + 1;
	}
}

int Operator::cmd_proc(const std::string &cmd_str, ClientRef sender)
{
	int res = 0;

	_cmd_idx = 0;
	_cmd_str = cmd_str;
	_sender = sender;

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
	case CMD_KILL:
		res = _kill();
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
	case UNKNOWN:
		; // ?
		break;
	default:
		break;
	}
	_argu.clear();
	return (1);
}