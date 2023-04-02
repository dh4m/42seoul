/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:54:01 by dham              #+#    #+#             */
/*   Updated: 2023/04/02 22:24:45 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/event.h>
#include <sys/types.h>

Server::Server(int port, std::string passwd)
: _port(port), _passwd(passwd)
{}

Server::~Server(void)
{

}

int Server::init(void)
{
	_socket = socket(PF_INET, SOCK_STREAM, 0);
	if (!_socket)
	{
		;// err
	}
	struct sockaddr_in addr;
	
	
}