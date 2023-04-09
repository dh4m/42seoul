/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:54:01 by dham              #+#    #+#             */
/*   Updated: 2023/04/09 20:13:29 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <sys/socket.h>
#include <cstring>
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
	return (1);
}

int Server::run(void)
{

}