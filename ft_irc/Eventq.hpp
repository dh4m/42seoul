/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eventq.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:03:05 by dham              #+#    #+#             */
/*   Updated: 2023/04/02 21:08:12 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EVENTQ_HPP
# define EVENTQ_HPP

#include <sys/time.h>
#include <sys/event.h>
#include <sys/types.h>

class Eventq
{
public:
	Eventq(void);
	~Eventq(void);

	int init(void);
	
private:
	int _kq;

	Eventq	&operator=(const Eventq &copy);
	Eventq(const Eventq &copy);
};

#endif
