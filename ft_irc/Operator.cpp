/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:23:26 by dham              #+#    #+#             */
/*   Updated: 2023/07/12 19:40:58 by dham             ###   ########.fr       */
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

int Operator::cmd_proc(const std::string &cmd_str, ClientRef sender)
{
	int res = 0;

	_cmd_str = cmd_str;
	_sender = sender;

	if (!_parsing_msg())
	{
		//err
		return (0);
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