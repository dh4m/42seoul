/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:54:01 by dham              #+#    #+#             */
/*   Updated: 2023/05/06 22:00:14 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <sys/socket.h>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

Server::Server(int port, std::string passwd)
: _port(port), _err_state(0)
{
	if (!passwd.empty())
		_passwd = passwd;
	memset(&_addr, 0, sizeof(_addr));
}

Server::~Server(void)
{
	
}

int Server::init(void)
{
	_socket = socket(PF_INET, SOCK_STREAM, 0);
	if (!_socket)
	{
		;// err
		return (0);
	}
	_addr.sin_family = AF_INET;
	_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	_addr.sin_port = htons(_port);
	if (bind(_socket, (struct sockaddr *)&_addr, sizeof(_addr)) == -1)
	{
		;//err
		return (0);
	}
	if (listen(_socket, 5) == -1)
	{
		;//err
		return (0);
	}
	fcntl(_socket, F_SETFL, O_NONBLOCK);
	_ev_q.reg_event(_socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	return (1);
}

int Server::run(void)
{
	int new_event;
	struct kevent ev_list[ACCEPT_EV_NUM];
	int i;

	while (1)
	{
		new_event = _ev_q.get_event(ev_list, ACCEPT_EV_NUM);
		if (new_event == -1)
		{
			;//err
			return (0);
		}
		
		for (i = 0; i < new_event; i++)
		{
			if (ev_list[i].flags & EV_ERROR)
			{

			}
			else if (ev_list[i].flags == EVFILT_WRITE)
			{

			}
			else if (ev_list[i].flags == EVFILT_READ)
			{

			}
		}
	}
}