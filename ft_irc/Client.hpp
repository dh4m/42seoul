/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:12:59 by dham              #+#    #+#             */
/*   Updated: 2023/06/19 22:14:09 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include <string>
#include <vector>
#include <deque>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>

#define INPUT_BUF_SIZE 1024

enum e_result
{
	LOCK_FAIL = -2,
	ERROR = -1,
	DISCONNECT = 0,
	SUCCESS = 1
};

class Client
{
public:
	Client(int fd);
	~Client(void);

	void add_output(std::string &str);
	int get_fd(void);
	int client_read(void);
	int client_write(void);
	bool output_exist(void);
	bool usable_client(void);
	void client_err_close(const char *err_msg);

private:
	bool _client_lock(void);
	void _client_unlock(void);

	// pthread_mutex_t _client_m;
	// bool _lock_client;

	int _fd;

	std::string _input_buf;
	pthread_mutex_t _client_input_m;

	std::deque<std::string> _output_buf;
	pthread_mutex_t _client_output_m;
	// std::vector<unsigned char> _file_buf;

	Client(const Client &copy);
	Client	&operator=(const Client &copy);
};

#endif
