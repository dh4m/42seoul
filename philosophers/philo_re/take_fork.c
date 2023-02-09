/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:29:56 by dham              #+#    #+#             */
/*   Updated: 2023/02/09 19:47:50 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

int	take_fork(t_philo *philo, t_fork *fork)
{
	while (1)
	{
		pthread_mutex_lock(&philo->info->ready_m);
		if (!philo->info->all_ready)
			break ;
		pthread_mutex_unlock(&philo->info->ready_m);
		pthread_mutex_lock(&(fork->mutex));
		if (fork->state)
		{
			fork->state = 0;
			pthread_mutex_unlock(&(fork->mutex));
			if (!mutex_print("%d %d has taken a fork\n", \
				philo->num, philo->info))
				return (-1);
			return (1);
		}
		else
			pthread_mutex_unlock(&(fork->mutex));
		usleep(300);
	}
	pthread_mutex_unlock(&philo->info->ready_m);
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
