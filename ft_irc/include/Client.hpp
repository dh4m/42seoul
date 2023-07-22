/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:12:59 by dham              #+#    #+#             */
/*   Updated: 2023/07/22 19:57:08 by dham             ###   ########.fr       */
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

enum e_userstate
{
	NEEDNICK,
	NEEDUSER,
	AVAIL_USER,
	OPERATOR,
	UNAVAIL_USER
};

class Client
{
public:
	Client(int fd);
	~Client(void);

	void pass_client(void);
	void nick_set(std::string &nick);
	std::string get_nick(void);
	std::string get_user(void);
	std::string get_host(void);
	std::string get_prifix(void);
	void user_init(std::string &user, std::string &host, std::string &real);
	int avail_client(void);
	int set_user_state(int state);

	void add_output(std::string &str);
	int get_fd(void) const;
	void get_input_buffer(std::string &str);
	int client_read(void);
	int client_write(void);
	bool exist_output(void);
	void leave_all_channel(void);

	int include_chan(std::string &channame);
private:
	int _fd;
	std::string _username;
	std::string _nickname;
	pthread_mutex_t _client_nickname_m; // rwlock 변경
	std::string _hostname;
	std::string _realname;
	std::string _passwd;

	int _user_state;
	std::bitset<3> _client_regist;

	std::string _input_buf;
	pthread_mutex_t _client_input_m;

	std::string _output_buf;
	pthread_mutex_t _client_output_m;

	std::vector<std::string> _chan;
	
	Client	&operator=(const Client &copy);
	Client(const Client &copy);
};

#endif
