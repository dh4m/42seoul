/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:58:45 by dham              #+#    #+#             */
/*   Updated: 2023/06/18 20:26:31 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WORKER_HPP
# define WORKER_HPP

#include "ClientInfo.hpp"
#include <deque>

#define NUM_THREAD 12

enum e_command
{
	M_READ,
	M_WRITE
};

typedef struct s_msg
{
	std::string str;
	int cmd;
} t_msg;

class Worker
{
public:
	Worker(void);
	~Worker(void);

	int init(void);
	void add_client(int fd);
	void remove_client(int fd, const char *msg);
	void reg_msg(int fd, int cmd);
	void reg_err_msg(int fd);
private:
	ClientInfo _client;
	std::deque<t_msg> _messageQ;

	Worker(const Worker &copy);
	Worker	&operator=(const Worker &copy);
};

#endif
