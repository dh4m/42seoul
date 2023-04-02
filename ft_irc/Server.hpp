/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:54:07 by dham              #+#    #+#             */
/*   Updated: 2023/04/02 22:07:41 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SERVER_HPP
# define SERVER_HPP

#include <iostream>
#include <sys/socket.h>

class Server
{
public:
	Server::Server(int port, std::string passwd);
	~Server(void);

	int init(void);
private:
	int _port;
	std::string _passwd;
	int _socket;

	Server	&operator=(const Server &copy);
	Server(const Server &copy);
};

#endif
