/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:29:56 by dham              #+#    #+#             */
/*   Updated: 2022/08/21 14:12:11 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philo.h"

int	take_fork(t_philo *philo, t_fork *fork)
{
	while (philo->info->all_ready)
	{
		pthread_mutex_lock(&(fork->mutex));
		if (fork->state)
		{
			fork->state = 0;
			if (philo->info->all_ready)
				printf("%d %d has taken a fork\n", \
					diff_time(philo->info->s_time), philo->num);
			else
				return (-1);
			pthread_mutex_unlock(&(fork->mutex));
			return (1);
		}
		else
			pthread_mutex_unlock(&(fork->mutex));
		usleep(300);
	}
	return (0);
}

int	take_leftfirst(t_philo *philo)
{
	take_fork(philo, philo->left_fork);
	take_fork(philo, philo->right_fork);
	return (0);
}

int	take_rightfirst(t_philo *philo)
{
	take_fork(philo, philo->right_fork);
	take_fork(philo, philo->left_fork);
	return (0);
}
