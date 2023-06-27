/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eventq.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:05:07 by dham              #+#    #+#             */
/*   Updated: 2023/06/27 21:03:56 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Eventq.hpp"
#include <iostream>

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
	return (1);
}

int Eventq::reg_event(int socket, int16_t filter, uint16_t flag, uint16_t fflage, intptr_t data, void *udata)
{
	t_event temp;

	EV_SET(&temp, socket, filter, flag, fflage, data, udata);
	kevent(_kq, &temp, 1, NULL, 0, NULL);
	return (1);
}

int Eventq::get_event(t_event event[], int len)
{
	int event_num;

	event_num = kevent(_kq, NULL, 0, event, len, NULL);
	return (event_num);
}
