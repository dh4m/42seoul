/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:23:40 by dham              #+#    #+#             */
/*   Updated: 2023/07/17 18:20:57 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef OPERATOR_HPP
# define OPERATOR_HPP

#include <vector>
#include <string>
#include <sstream>

#include "Server.hpp"
#include "ClientInfo.hpp"

#define SPACE ' '

enum e_cmd_msg
{
	CMD_PASS, 
	CMD_NICK,
	CMD_USER,
	CMD_JOIN,
	CMD_PRIVMSG,
	CMD_NOTICE,
	CMD_OPER,
	CMD_KICK,
	CMD_INVITE,
	CMD_MODE,
	CMD_TOPIC,
	CMD_QUIT,
	CMD_PART,
	CMD_PING,
	UNKNOWN
};

enum e_reply
{
	ERR_ALREADYRGISTRED,
	ERR_NEEDMOREPARAMS,
	ERR_PASSWDMISMATCH
};

class Operator
{
public:
	Operator(ClientInfo &info, std::string passwd);
	~Operator(void);

	int cmd_proc(const std::string &cmd_str, ClientRef sender);
private:
	int _parsing_msg(void);
	int _prefix_setting(void);
	int _cmd_setting(void);
	void _argu_setting(void);

	int _pass(void);
	int _nick(void);
	int _avail_nick(void);
	int _user(void);
	int _join(void);
	int _privmsg(void);
	int _notice(void);
	int _oper(void);
	int _kick(void);
	int _invite(void);
	int _mode(void);
	int _topic(void);
	int _quit(void);
	int _part(void);
	int _ping(void);

	std::string _reply_make(int reply);

	ClientInfo &_info;
	std::string _cmd_str;
	size_t _cmd_length;
	size_t _cmd_idx;
	ClientRef _sender;

	std::string _prefix;
	int _command;
	std::vector<std::string> _argu;

	std::string _passwd;

	Operator(const Operator &copy);
	Operator	&operator=(const Operator &copy);
};

#endif
