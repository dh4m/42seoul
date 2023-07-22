/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:12:40 by dham              #+#    #+#             */
/*   Updated: 2023/07/22 14:51:10 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"
#include "ClientInfo.hpp"
#include "Eventq.hpp"
#include "ScopeLock.hpp"
#include <iostream>
#include <unistd.h>

Client::Client(int fd)
: _fd(fd), _user_state(NEEDPASS), \
_username("*"), _realname("*"), _nickname("*")
{
	pthread_mutex_init(&_client_input_m, NULL);
	pthread_mutex_init(&_client_output_m, NULL);
	pthread_mutex_init(&_client_nickname_m, NULL);
}

Client::~Client(void)
{
	close(_fd);
	pthread_mutex_destroy(&_client_input_m);
	pthread_mutex_destroy(&_client_output_m);
	pthread_mutex_destroy(&_client_nickname_m);
}

/// 유저인증과정 개선   
void Client::pass_client(void)
{
	_user_state = NEEDNICK;
}

void Client::nick_set(std::string &nick)
{
	{
		ScopeLock lock(&_client_nickname_m);
		_nickname = nick;
	}
	if (_user_state == NEEDNICK)
		_user_state = NEEDUSER;
}

void Client::user_init(std::string &user, std::string &host, std::string &real)
{
	_username = user;
	_realname = real;
	_hostname = host;
	_user_state = AVAIL_USER;
}

int Client::avail_client(void)
{
	return (_user_state);
}

int Client::set_user_state(int state)
{
	_user_state = state;
}

std::string Client::get_nick(void)
{
	ScopeLock lock(&_client_nickname_m);
	return (_nickname);
}
std::string Client::get_user(void)
{
	return (_username);
}

std::string Client::get_host(void)
{
	return (_hostname);
}


void Client::add_output(std::string &str)
{
	str += CRLF;
	{
		ScopeLock lock(&_client_output_m);
		_output_buf += str;
	}
	Eventq::getInstance().reg_event(_fd, EVFILT_WRITE, EV_ENABLE, 0, 0, NULL);
}

bool Client::exist_output(void)
{
	bool res;

	{
		ScopeLock lock(&_client_output_m);
		res = !_output_buf.empty();
	}
	return (res);
}

int Client::get_fd(void) const
{
	return (_fd);
}

int Client::client_read(void)
{
	char buf[INPUT_BUF_SIZE];
	int ret_recv;

	ScopeLock lock(&_client_input_m);
	// input 중복 문제 해결?
	ret_recv = recv(_fd, buf, INPUT_BUF_SIZE - 1, 0);
	if (ret_recv == 0)
	{
		///
		std::cout << _fd << " disconnected" << std::endl;
		///remove client
		return (DISCONNECT); //client disconnect
	}
	if (ret_recv < 0)
	{
		std::cout << _fd << std::endl;
		std::cout << "Error occuar  " << errno << std::endl;
		return (ERROR);
	}
	buf[ret_recv] = 0;
	_input_buf += buf;
	
	///
	std::cout << _fd << " input " << _input_buf << std::endl;
	return (ret_recv);
}

int Client::client_write(void)
{
	int output = 0;


	ScopeLock lock(&_client_output_m);
	if ((output = send(_fd, _output_buf.data(), _output_buf.length(), 0)) == -1)
	{
		return (ERROR);
	}
	_output_buf.erase(0, output);
	return (_output_buf.length());
}

void Client::leave_all_channel(void)
{
	
}

void Client::get_input_buffer(std::string &str)
{
	size_t del = 0;

	{
		ScopeLock lock(&_client_input_m);
		del = _input_buf.find(CRLF);
		if (del != std::string::npos)
		{
			str = _input_buf.substr(0, del);
			_input_buf = _input_buf.substr(del + 2);
		}
		else
			str.clear();
	}
}
