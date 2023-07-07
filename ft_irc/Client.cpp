/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:12:40 by dham              #+#    #+#             */
/*   Updated: 2023/07/07 19:39:41 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"
#include "ClientInfo.hpp"
#include "Eventq.hpp"
#include "ScopeLock.hpp"
#include <iostream>
#include <unistd.h>

Client::Client(int fd, ClientInfo &info)
: _fd(fd), _info_another(info)
{
	pthread_mutex_init(&_client_input_m, NULL);
	pthread_mutex_init(&_client_output_m, NULL);
}

Client::~Client(void)
{
	leave_all_channel();
	close(_fd);
	pthread_mutex_destroy(&_client_input_m);
	pthread_mutex_destroy(&_client_output_m);
}

void Client::add_output(std::string &str)
{
	// 순서 보장 문제
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
		///

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

	if (_input_buf.find(CRLF))
	{
		_info_another.server_all_notice(_input_buf, _fd);
		_input_buf.clear();
	}

	//if (_input_buf.find(CRLF))
	//{

		// _info_another.find_chan("chan_name")
		// for (t_clientlist::iterator it = _info_another.)
		// add_output(_input_buf);
		// _input_buf.clear();
	//}
	///

	return (ret_recv);
}

int Client::client_write(void)
{
	int num_output = 0;

	ScopeLock lock(&_client_output_m);
	if (send(_fd, _output_buf.data(), _output_buf.length(), 0) == -1)
	{
		return (ERROR);
	}
	_output_buf.clear();
	return (num_output);
}

void Client::leave_all_channel(void)
{
	
}
