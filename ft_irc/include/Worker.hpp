/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:58:45 by dham              #+#    #+#             */
/*   Updated: 2023/06/22 15:54:56 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WORKER_HPP
# define WORKER_HPP

#include "ClientInfo.hpp"
#include <deque>
#include <map>
#include <set>

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

typedef struct s_channelInfo
{
	std::set<Client*> member;
	// info
}	t_chnnelInfo;

typedef std::map< std::string, t_chnnelInfo > t_chanlist;

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
	int _read_client(Client *op_cl);
	int _write_client(Client *op_cl);
	int _ctrl_msg(std::string str);

	static void *_worker_thread_func(void *args);
	ClientInfo _client;
	t_chanlist _channel;
	t_messageQ _msgQ;

	std::vector<pthread_t> _thread_list;

	Worker(const Worker &copy);
	Worker	&operator=(const Worker &copy);
};

#endif
