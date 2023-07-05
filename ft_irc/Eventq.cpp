/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eventq.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:05:07 by dham              #+#    #+#             */
/*   Updated: 2023/07/05 19:09:25 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Eventq.hpp"
#include <iostream>
#include <fcntl.h>

Eventq::Eventq(void) {}
Eventq::~Eventq(void) {}

Eventq &Eventq::getInstance(void)
{
	static Eventq singleton_obj;
	return (singleton_obj);
}

int Eventq::init(void)
{
	_kq = kqueue();
	if (!_kq)
	{
		;/// err
		return (0);
	}
	if (pipe(_trigger_pipe) == -1)
	{
		;/// err
		return (0);
	}
	fcntl(_trigger_pipe[0], F_SETFL, O_NONBLOCK);
	fcntl(_trigger_pipe[1], F_SETFL, O_NONBLOCK);
	pthread_mutex_init(&_mutex_change_list, NULL);
	reg_event(_trigger_pipe[0], EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	return (1);
}

int Eventq::reg_event(int socket, int16_t filter, uint16_t flag, uint16_t fflage, intptr_t data, void *udata)
{
	t_event temp;

	EV_SET(&temp, socket, filter, flag, fflage, data, udata);
	pthread_mutex_lock(&_mutex_change_list);
	_change_list.push_back(temp);
	_trigger_send();
	pthread_mutex_unlock(&_mutex_change_list);
	return (1);
}

int Eventq::get_event(t_event event[], int len)
{
	int event_num;
	std::vector<t_event> tmp_list;
	
	event_num = kevent(_kq, NULL, 0, event, len, NULL);

	do
	{
		pthread_mutex_lock(&_mutex_change_list);
		if (_change_list.size())
			kevent(_kq, _change_list.data(), _change_list.size(), NULL, 0, NULL);
		read(_trigger_pipe[0], _flush_buf, PIPE_BUF);
		pthread_mutex_unlock(&_mutex_change_list);
		event_num = kevent(_kq, NULL, 0, event, len, NULL);
		
	} while (event_num == 1 && event[0].ident == _trigger_pipe[0]);
	return (event_num);
}

int Eventq::_trigger_send(void)
{
	write(_trigger_pipe[1], "\0", 1);
}

void Eventq::destroy_eventq(void)
{
	close(_trigger_pipe[0]);
	close(_trigger_pipe[1]);
}
