/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:29:56 by dham              #+#    #+#             */
/*   Updated: 2022/08/10 19:23:30 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include "philo.h"

int	take_leftfirst(t_philo *philo)
{
	struct timeval	tv;

	pthread_mutex_lock(&(philo->left_fork->mutex));
	gettimeofday(&tv, NULL);
	printf("%d %d has taken a fork\n", \
			diff_time(tv, philo->s_time), philo->num);
	pthread_mutex_lock(&(philo->right_fork->mutex));
	gettimeofday(&tv, NULL);
	printf("%d %d has taken a fork\n", \
			diff_time(tv, philo->s_time), philo->num);
	return (0);
}

int	take_rightfirst(t_philo *philo)
{
	struct timeval	tv;

	pthread_mutex_lock(&(philo->right_fork->mutex));
	gettimeofday(&tv, NULL);
	printf("%d %d has taken a fork\n", \
			diff_time(tv, philo->s_time), philo->num);
	pthread_mutex_lock(&(philo->left_fork->mutex));
	gettimeofday(&tv, NULL);
	printf("%d %d has taken a fork\n", \
			diff_time(tv, philo->s_time), philo->num);
	return (0);
}

int	free_fork(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	pthread_mutex_unlock(&(philo->right_fork->mutex));
	return (0);
}
