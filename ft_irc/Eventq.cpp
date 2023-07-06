/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eventq.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:05:07 by dham              #+#    #+#             */
/*   Updated: 2023/07/06 22:07:26 by dham             ###   ########.fr       */
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
	pthread_mutex_init(&_mutex_change_list, NULL);
	reg_event(NOTIFY_IDENT, EVFILT_USER, EV_ADD | EV_ENABLE, 0, 0, NULL);
	return (1);
}

int Eventq::reg_event(int socket, int16_t filter, uint16_t flag, uint16_t fflage, intptr_t data, void *udata)
{
	t_event temp;

	EV_SET(&temp, socket, filter, flag, fflage, data, udata);
	pthread_mutex_lock(&_mutex_change_list);
	_change_list.push_back(temp);
	pthread_mutex_unlock(&_mutex_change_list);
	return (1);
}

int Eventq::get_event(t_event event[], int len)
{
	int event_num;

	pthread_mutex_lock(&_mutex_change_list);
	std::vector<t_event> tmp_list(_change_list);
	pthread_mutex_unlock(&_mutex_change_list);
	event_num = kevent(_kq, tmp_list.data(), tmp_list.size(), event, len, NULL);

	while (USER)
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
