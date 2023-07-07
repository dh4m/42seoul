/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eventq.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:05:07 by dham              #+#    #+#             */
/*   Updated: 2023/07/07 18:44:48 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Eventq.hpp"
#include <iostream>
#include <fcntl.h>
#include "ScopeLock.hpp"

Eventq::Eventq(void) {}
Eventq::~Eventq(void) {}

Eventq &Eventq::getInstance(void)
{
	static Eventq singleton_obj;
	return (singleton_obj);
}

int Eventq::init(void)
{
	t_event temp;

	_kq = kqueue();
	if (!_kq)
	{
		;/// err
		return (0);
	}
	pthread_mutex_init(&_mutex_change_list, NULL);
	EV_SET(&temp, NOTIFY_IDENT, EVFILT_USER, EV_ADD | EV_ENABLE, 0, 0, NULL);
	kevent(_kq, &temp, 1, NULL, 0, NULL);
	return (1);
}

int Eventq::reg_event(int socket, int16_t filter, uint16_t flag, uint16_t fflage, intptr_t data, void *udata)
{
	t_event temp;

	EV_SET(&temp, socket, filter, flag, fflage, data, udata);
	{
		ScopeLock lock(&_mutex_change_list);
		_change_list.push_back(temp);
	}
	_forced_trigger();
	return (1);
}

int Eventq::get_event(t_event event[], int len)
{
	int event_num;
	std::vector<t_event> tmp_list;
	
	do
	{
		{
			ScopeLock lock(&_mutex_change_list);
			tmp_list = _change_list;
		}
		event_num = kevent(_kq, tmp_list.data(), tmp_list.size(), event, len, NULL);
	} while (event_num == 1 && event[0].filter == EVFILT_USER && event[0].ident == NOTIFY_IDENT);
	return (event_num);
}

void Eventq::destroy_eventq(void)
{
	pthread_mutex_destroy(&_mutex_change_list);
	close(_kq);
}

void Eventq::_forced_trigger(void)
{
	t_event trigger;

	EV_SET(&trigger, NOTIFY_IDENT, EVFILT_USER, 0, NOTE_TRIGGER, 0, NULL);
	kevent(_kq, &trigger, 1, NULL, 0, NULL);
}
