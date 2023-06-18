/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eventq.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:05:07 by dham              #+#    #+#             */
/*   Updated: 2023/05/06 14:21:29 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Eventq.hpp"

Eventq::Eventq(void)
{}

Eventq::~Eventq(void)
{

}

int Eventq::init(void)
{
	_kq = kqueue();
	if (!_kq)
	{
		;/// err
		return (0);
	}
}

int Eventq::reg_event(int socket, int16_t filter, uint16_t flag, uint16_t fflage, intptr_t data, void *udata)
{
	struct kevent temp;

	EV_SET(&temp, socket, filter, flag, fflage, data, udata);
	change_list.push_back(temp);
}

int Eventq::get_event(struct kevent event[], int len)
{
	int event_num;

	event_num = kevent(_kq, change_list.data(), change_list.size(), event, len, NULL);
	change_list.clear();
	return (event_num);
}