/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScopeLock.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:18:59 by dham              #+#    #+#             */
/*   Updated: 2023/07/07 18:20:11 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCOPELOCK_HPP
# define SCOPELOCK_HPP

#include <pthread.h>

class ScopeLock
{
public:
	ScopeLock(pthread_mutex_t *lock);
	~ScopeLock(void);

private:
	pthread_mutex_t *_lock;

	ScopeLock	&operator=(const ScopeLock &copy);
	ScopeLock(const ScopeLock &copy);
};

#endif
