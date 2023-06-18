/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:12:59 by dham              #+#    #+#             */
/*   Updated: 2023/05/06 21:58:34 by dham             ###   ########.fr       */
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

class Client
{
public:
	Client(int fd);
	~Client(void);

	void add_output(std::string &str);
	int get_fd(void);
	int client_read(std::string &str);
	int client_write(void);
	bool output_exist(void);
	bool usable_client(void);
private:
	pthread_mutex_t _client_m;
	int _fd;
	std::deque<std::string> _output_buf;
	// std::vector<unsigned char> _file_buf;

	Client(const Client &copy);
	Client	&operator=(const Client &copy);
};

#endif
