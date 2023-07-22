/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Worker.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:58:24 by dham              #+#    #+#             */
/*   Updated: 2023/07/22 17:48:33 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"
#include "Eventq.hpp"
#include "Operator.hpp"
#include "ScopeLock.hpp"
#include <iostream>

Worker::Worker(void)
{
	pthread_cond_init(&_msgQ._q_fill_cond, NULL);
	pthread_mutex_init(&_msgQ._msgq_m, NULL);
	_thread_list.reserve(NUM_THREAD);
}

int Worker::_worker_status = 1;

Worker::~Worker(void)
{
	pthread_cond_destroy(&_msgQ._q_fill_cond);
	pthread_mutex_destroy(&_msgQ._msgq_m);
}

int Worker::init(const std::string &passwd)
{
	_passwd = passwd;
	for(int i = 0; i < NUM_THREAD; i++)
	{
		pthread_create(&_thread_list[i], NULL, \
						_worker_thread_func, this);
	}
	return (1);
}

void Worker::add_client(int fd)
{
	_client.add_client(fd);
}

void Worker::remove_client(int fd, const char *msg)
{
	_client.remove_client(fd, msg);
}

void Worker::reg_msg(int fd, int cmd)
{
	t_msg insert_msg = {.fd = fd, .cmd = cmd};
	Eventq & ev_q = Eventq::getInstance();

	ScopeLock lock(&_msgQ._msgq_m);
	if (cmd == M_READ)
		ev_q.reg_event(fd, EVFILT_READ, EV_DISABLE, 0, 0, NULL);
	else if(cmd == M_WRITE)
		ev_q.reg_event(fd, EVFILT_WRITE, EV_DISABLE, 0, 0, NULL);
	else
		return ;
	_msgQ._messageQ.push_back(insert_msg);
	pthread_cond_signal(&_msgQ._q_fill_cond);
}

int Worker::destroy(void)
{
	_worker_status = 0;
	pthread_cond_broadcast(&_msgQ._q_fill_cond);
	for (int i = 0; i < NUM_THREAD; i++)
	{
		pthread_join(_thread_list[i], NULL);
	}
	_client.destroy();
	return (0);
}

void *Worker::_worker_thread_func(void *args)
{
	Worker &info = *(Worker *)args;
	t_messageQ &q = info._msgQ;
	t_msg curr_msg;
	ClientRef op_cl;
	Eventq &ev_q = Eventq::getInstance();
	Operator operate_cmd(info._client, info._passwd);
	std::string input;

	while (_worker_status)
	{
		op_cl = ClientRef::NullClientRef();
		pthread_mutex_lock(&q._msgq_m);
		while (q._messageQ.empty())
		{
			pthread_cond_wait(&q._q_fill_cond, &q._msgq_m);
			if (!_worker_status)
			{
				pthread_mutex_unlock(&q._msgq_m);
				return (NULL);
			}
		}
		curr_msg = q._messageQ.front();
		q._messageQ.pop_front();
		pthread_mutex_unlock(&q._msgq_m);
		op_cl = info._client.find_client(curr_msg.fd);
		if (!op_cl)
			continue;
		if (curr_msg.cmd == M_READ)
		{
			std::cout << op_cl->get_fd() << " read accept!!!" << std::endl;
			op_cl->client_read();
			op_cl->get_input_buffer(input);
			while (!input.empty())
			{
				operate_cmd.cmd_proc(input, op_cl);
				op_cl->get_input_buffer(input);
			}
			if (op_cl->avail_client() != UNAVAIL_USER)
				ev_q.reg_event(op_cl->get_fd(), EVFILT_READ, EV_ENABLE, 0, 0, NULL);
		}
		else if (curr_msg.cmd == M_WRITE)
		{
			op_cl->client_write();
			if (op_cl->exist_output() && op_cl->avail_client() != UNAVAIL_USER)
				ev_q.reg_event(op_cl->get_fd(), EVFILT_WRITE, EV_ENABLE, 0, 0, NULL);
		}
	}
	op_cl = ClientRef::NullClientRef();
	return (NULL);
}