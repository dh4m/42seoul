/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:12:40 by dham              #+#    #+#             */
/*   Updated: 2023/06/19 22:38:18 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client(int fd)
: _fd(fd)// , _lock_client(0)
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

	if (pthread_mutex_trylock(&_client_input_m) == -1)
		return (LOCK_FAIL);
	// input 중복 문제 해결
	ret_recv = recv(_fd, buf, INPUT_BUF_SIZE - 1, 0);
	if (ret_recv == 0)
	{
		pthread_mutex_unlock(&_client_input_m);
		return (DISCONNECT); //client disconnect
	}
	while (ret_recv > 0)
	{
		buf[ret_recv] = 0;
		_input_buf += buf;
		ret_recv = recv(_fd, buf, INPUT_BUF_SIZE - 1, 0);
	}
	pthread_mutex_unlock(&_client_input_m);
	if (ret_recv < 0)
	{
		return (ERROR);
	}
	return (ret_recv);
}

int Client::client_write(void)
{
	int num_output = 0;

	if (pthread_mutex_trylock(&_client_output_m) == -1)
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

/*
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
*/