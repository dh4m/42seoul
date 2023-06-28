/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eventq.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:03:05 by dham              #+#    #+#             */
/*   Updated: 2023/06/28 13:10:10 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EVENTQ_HPP
# define EVENTQ_HPP

#include <sys/time.h>
#include <sys/event.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include <pthread.h>

typedef struct kevent t_event;

class Eventq
{
public:
	static Eventq &getInstance(void);

	int init(void);
	int reg_event(int socket, int16_t filter, uint16_t flag, uint16_t fflage, intptr_t data, void *udata);
	int get_event(t_event event[], int len);
	int trigger_send(void);
	// void destroy_eventq(void);
private:
	int _kq;
	int _trigger_pipe[2];
	std::vector<t_event> change_list;
	
	Eventq	&operator=(const Eventq &copy);
	Eventq(const Eventq &copy);
	Eventq(void);
	~Eventq(void);
};

#endif
