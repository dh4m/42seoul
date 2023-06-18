/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:54:07 by dham              #+#    #+#             */
/*   Updated: 2023/05/06 14:36:17 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SERVER_HPP
# define SERVER_HPP

# define ACCEPT_EV_NUM 10

#include "Eventq.hpp"
#include "ThreadPool.hpp"
#include "ClientInfo.hpp"

#include <iostream>
#include <map>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/event.h>
#include <sys/types.h>

class Server
{
public:
	Server::Server(int port, std::string passwd);
	~Server(void);

	int init(void);
	int run(void);
	void errDetect(void);
private:
	int _port;
	std::string _passwd;
	int _socket;
	struct sockaddr_in _addr;
	int _err_state;

	Eventq _ev_q;
	ThreadPool _thr_pool;
	std::map<int, ClientInfo> _client_list;

	Server	&operator=(const Server &copy);
	Server(const Server &copy);
};

#endif
