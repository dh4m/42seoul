/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:58:45 by dham              #+#    #+#             */
/*   Updated: 2023/06/24 18:32:36 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WORKER_HPP
# define WORKER_HPP

#include "ClientInfo.hpp"
#include <deque>
#include <map>
#include <set>
#include <string>

#define NUM_THREAD 12

enum e_command
{
	M_READ,
	M_WRITE
};

typedef struct s_msg
{
	int fd;
	int cmd;
} t_msg;

typedef struct s_messageQ
{
	std::deque<t_msg> _messageQ;
	pthread_mutex_t _msgq_m;
	pthread_cond_t _q_fill_cond;
}	t_messageQ;

class Worker
{
public:
	Worker(void);
	~Worker(void);

	int init(const std::string &passwd);
	void add_client(int fd);
	void remove_client(int fd, const char *msg);
	void reg_msg(int fd, int cmd);
	void reg_err_msg(int fd);
private:
	static void *_worker_thread_func(void *args);

	std::string _passwd;
	ClientInfo _client;
	t_messageQ _msgQ;
	std::vector<pthread_t> _thread_list;

	Worker(const Worker &copy);
	Worker	&operator=(const Worker &copy);
};

#endif
