/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eventq.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:03:05 by dham              #+#    #+#             */
/*   Updated: 2023/05/02 16:35:02 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EVENTQ_HPP
# define EVENTQ_HPP

#include <sys/time.h>
#include <sys/event.h>
#include <sys/types.h>
#include <vector>

class Eventq
{
public:
	Eventq(void);
	~Eventq(void);

	int init(void);
	int reg_event(int socket, int16_t filter, uint16_t flag, uint16_t fflage, intptr_t data, void *udata);
	int get_event(struct kevent event[], int len);
private:
	int _kq;
	std::vector<struct kevent> change_list;
	
	Eventq	&operator=(const Eventq &copy);
	Eventq(const Eventq &copy);
};

#endif
