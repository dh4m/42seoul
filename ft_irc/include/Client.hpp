/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:12:59 by dham              #+#    #+#             */
/*   Updated: 2023/07/12 17:16:43 by dham             ###   ########.fr       */
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
#define CRLF "\r\n"

enum e_result
{
	LOCK_FAIL = -2,
	ERROR = -1,
	DISCONNECT = 0,
	SUCCESS = 1
};

enum e_clientmode
{
	INVISIBLE,
	NOTICE,
	OPERATOR
};

enum e_userstate
{
	NEEDPASS,
	NEEDNICK,
	NEEDUSER,
	AVAIL_USER
};

class ClientInfo;

class Client
{
public:
	Client(int fd, ClientInfo &info);
	~Client(void);

	void pass_client(void);
	void nick_set(std::string &nick);
	void user_init(std::string &user, std::string &real);

	int avail_client(void);

	void add_output(std::string &str);
	int get_fd(void) const;
	void get_input_buffer(std::string &str);
	int client_read(void);
	int client_write(void);
	bool exist_output(void);
	void leave_all_channel(void);

private:
	int _fd;
	std::string _username;
	std::string _nickname;
	std::string _realname;

	int _user_state;

	std::string _input_buf;
	pthread_mutex_t _client_input_m;

	std::string _output_buf;
	pthread_mutex_t _client_output_m;

	std::vector<std::string> _chan;
	
	Client	&operator=(const Client &copy);
	Client(const Client &copy);
};

#endif
