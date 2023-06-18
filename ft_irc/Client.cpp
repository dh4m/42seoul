/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:12:40 by dham              #+#    #+#             */
/*   Updated: 2023/05/06 21:55:42 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client(int fd)
: _fd(fd)
{
	pthread_mutex_init(&_client_m, NULL);
}

Client::~Client(void)
{
	pthread_mutex_destroy(&_client_m);
}

void Client::add_output(std::string &str)
{
	pthread_mutex_lock(&_client_m);
	_output_buf.push_back(str);
	pthread_mutex_unlock(&_client_m);
}

int Client::get_fd(void)
{
	return (_fd);
}

int Client::client_read(std::string &str)
{
	char input_buf[INPUT_BUF_SIZE];
	int ret_recv;

	ret_recv = recv(_fd, input_buf, INPUT_BUF_SIZE - 1, 0);
	if (ret_recv <= 0)
	{
		;////client close
	}
	while (ret_recv > 0)
	{
		input_buf[ret_recv] = 0;
		str += input_buf;
		ret_recv = recv(_fd, input_buf, INPUT_BUF_SIZE - 1, 0);
	}
}

int Client::client_write(void)
{
	std::string output_str;

	pthread_mutex_lock(&_client_m);
	output_str = _output_buf[0];
	send(_fd, output_str.data(), output_str.length(), 0);
	_output_buf.pop_front();
	pthread_mutex_unlock(&_client_m);
}

bool Client::output_exist(void)
{
	bool ret_val;

	if (pthread_mutex_trylock(&_client_m) == -1)
	{
		return (false);
	}
	ret_val = !_output_buf.empty();
	pthread_mutex_unlock(&_client_m);
	return (ret_val);
}

bool Client::usable_client(void)
{
	if (pthread_mutex_trylock(&_client_m) == -1)
	{
		return (false);
	}
	pthread_mutex_unlock(&_client_m);
	return (true);
}
