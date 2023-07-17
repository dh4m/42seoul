/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:54:07 by dham              #+#    #+#             */
/*   Updated: 2023/07/17 19:23:17 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SERVER_HPP
# define SERVER_HPP

# define ACCEPT_EV_NUM 10

#include "Eventq.hpp"
#include "ClientInfo.hpp"
#include "Worker.hpp"

#include <iostream>
#include <map>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/event.h>
#include <sys/types.h>

#define COUNTOF(_x) (sizeof(_x) / sizeof((_x)[0]))
#define SERVER_NAME "ftirc.local"
#define OPER_NAME "root"
#define OPER_PASSWD "ircishard"

class Server
{
public:
	Server(int port, const char *passwd);
	~Server(void);

	int init(void);
	int run(void);
	int destroy(void);
private:
	void _add_client(int fd);

	int _port;
	std::string _passwd;
	int _socket;
	struct sockaddr_in _addr;

	Worker _worker;
	Eventq &_ev_q;

	Server	&operator=(const Server &copy);
	Server(const Server &copy);
};

#endif
