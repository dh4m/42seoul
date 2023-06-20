/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:12:40 by dham              #+#    #+#             */
/*   Updated: 2023/06/20 21:22:31 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"
#include <iostream>

Client::Client(int fd)
: _fd(fd)
{
	pthread_mutex_init(&_client_input_m, NULL);
	pthread_mutex_init(&_client_output_m, NULL);
}

Client::~Client(void)
{
	pthread_mutex_destroy(&_client_input_m);
	pthread_mutex_destroy(&_client_output_m);
}

void Client::add_output(std::string &str)
{
	// 순서 보장 문제
	pthread_mutex_lock(&_client_output_m);
	_output_buf.push_back(str);
	pthread_mutex_unlock(&_client_output_m);
}

int Client::get_fd(void)
{
	return (_fd);
}

int Client::client_read(void)
{
	char buf[INPUT_BUF_SIZE];
	int ret_recv;

	if (pthread_mutex_trylock(&_client_input_m) != 0)
		return (LOCK_FAIL);
	// input 중복 문제 해결?
	ret_recv = recv(_fd, buf, INPUT_BUF_SIZE - 1, 0);
	if (ret_recv == 0)
	{
		pthread_mutex_unlock(&_client_input_m);

		///
		std::cout << _fd << " disconnected" << std::endl;
		///

		return (DISCONNECT); //client disconnect
	}
	while (ret_recv > 0)
	{
		buf[ret_recv] = 0;
		_input_buf += buf;
		ret_recv = recv(_fd, buf, INPUT_BUF_SIZE - 1, 0);
	}
	pthread_mutex_unlock(&_client_input_m);
	
	///
	std::cout << _fd << " input " << _input_buf << std::endl;
	add_output(_input_buf);
	_input_buf.clear();
	///


	if (ret_recv < 0)
	{
		return (ERROR);
	}
	return (ret_recv);
}

int Client::client_write(void)
{
	int num_output = 0;

	if (pthread_mutex_trylock(&_client_output_m) != 0)
		return (LOCK_FAIL);
	while (!_output_buf.empty())
	{
		if (send(_fd, _output_buf.front().data(), _output_buf.front().length(), 0) == -1)
		{
			pthread_mutex_unlock(&_client_output_m);
			return (ERROR);
		}
		_output_buf.pop_front();
		num_output++;
	}
	pthread_mutex_unlock(&_client_output_m);
	return (num_output);
}
