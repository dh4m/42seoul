/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScopeLock.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:18:32 by dham              #+#    #+#             */
/*   Updated: 2023/07/07 18:21:58 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScopeLock.hpp"

ScopeLock::ScopeLock(pthread_mutex_t *lock)
: _lock(lock)
{
	if (_lock)
		pthread_mutex_lock(_lock);
}

ScopeLock::~ScopeLock(void)
{
	if (_lock)
		pthread_mutex_unlock(_lock);
}

