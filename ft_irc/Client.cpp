/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:12:40 by dham              #+#    #+#             */
/*   Updated: 2023/06/18 22:45:22 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client(int fd)
: _fd(fd), _lock_client(0)
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

int Client::client_read(void)
{
	char input_buf[INPUT_BUF_SIZE];
	int ret_recv;
	std::string rev_str;

	if (!_client_lock())
		return (-2); // lock fail
	ret_recv = recv(_fd, input_buf, INPUT_BUF_SIZE - 1, 0);
	if (ret_recv == 0)
	{
		; //client disconnect
	}
	while (ret_recv > 0)
	{
		input_buf[ret_recv] = 0;
		rev_str += input_buf;
		ret_recv = recv(_fd, input_buf, INPUT_BUF_SIZE - 1, 0);
	}
	if (ret_recv < 0)
	{
		_client_unlock();
		return (-1);
	}
	_client_unlock();

	//
	
	//
	
	return (ret_recv);
}

int Client::client_write(void)
{
	int num_output = 0;

	if (!_client_lock())
		return (-2); // lock fail
	while (!_output_buf.empty())
	{
		if (send(_fd, _output_buf.front().data(), _output_buf.front().length(), 0) == -1)
		{
			_client_unlock();
			return (-1);
		}
		_output_buf.pop_front();
		num_output++;
	}
	_client_unlock();
	return (num_output);
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

bool Client::usable_client(void) // 수정 필요
{
	if (pthread_mutex_trylock(&_client_m) == -1)
	{
		return (false);
	}
	pthread_mutex_unlock(&_client_m);
	return (true);
}

void Client::client_err_close(const char *err_msg)
{
	// client remove
}

bool Client::_client_lock(void)
{
	bool res = false;

	pthread_mutex_lock(&_client_m);
	if (_lock_client == 0)
	{
		_lock_client = 1;
		res = true;
	}
	pthread_mutex_unlock(&_client_m);
	return (res);
}

void Client::_client_unlock(void)
{
	pthread_mutex_lock(&_client_m);
	_lock_client = 0;
	pthread_mutex_unlock(&_client_m);
}
