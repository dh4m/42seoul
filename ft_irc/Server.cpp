/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:54:01 by dham              #+#    #+#             */
/*   Updated: 2023/07/22 17:13:53 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <sys/socket.h>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

Server::Server(int port, const char *passwd)
: _port(port), _passwd(passwd), _ev_q(Eventq::getInstance())
{
	memset(&_addr, 0, sizeof(_addr));
}

Server::~Server(void)
{}

int Server::init(void)
{
	if (!_ev_q.init())
	{
		; //err
		return (0);
	}
	_socket = socket(PF_INET, SOCK_STREAM, 0);
	if (!_socket)
	{
		;// err
		return (0);
	}
	int opt = true;
	setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
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
	t_event ev_list[ACCEPT_EV_NUM];
	int i;

	std::cout << "Server Start" << std::endl;
	_worker.init(_passwd);
	while (1)
	{
		new_event = _ev_q.get_event(ev_list, COUNTOF(ev_list));
		if (new_event == -1)
		{
			;//err
			return (0);
		}
		
		for (i = 0; i < new_event; i++)
		{
			if (ev_list[i].filter == EVFILT_USER)
				continue ;
			if (ev_list[i].flags & EV_ERROR)
			{
				if ((int)ev_list[i].ident == _socket)
				{
					std::cerr << "server socket Error" << std::endl;
					// server close
					return (0);
				}
				else
				{
					std::cerr << ev_list[i].ident << " client socket Error" << std::endl;
					// client remove
				}
			}
			else if ((int)ev_list[i].filter == EVFILT_READ)
			{
				if ((int)ev_list[i].ident == _socket)
				{
					int cl_fd;
					
					cl_fd = accept(_socket, NULL, NULL);
					if (cl_fd == -1)
					{
						std::cerr << "accept error" << std::endl;
						;// server close
						return (0);
					}
					_add_client(cl_fd);
				}
				else
				{
					_worker.reg_msg(ev_list[i].ident, M_READ);
				}
			}
			else if ((int)ev_list[i].filter == EVFILT_WRITE)
			{
				_worker.reg_msg(ev_list[i].ident, M_WRITE);
			}
		}
	}
	return (1);
}

void Server::_add_client(int fd)
{
	_worker.add_client(fd);
}

int Server::destroy(void)
{
	_worker.destroy();
	_ev_q.destroy_eventq();
	close(_socket);
	return (1);
}
