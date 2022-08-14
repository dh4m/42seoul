/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:29:56 by dham              #+#    #+#             */
/*   Updated: 2022/08/14 19:53:43 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	take_fork(t_fork *fork)
{
	while (1)
	{
		pthread_mutex_lock(&(fork->mutex));
		if (fork->state)
		{
			fork->state = 0;
			pthread_mutex_unlock(&(fork->mutex));
			return (1);
		}
		else
			pthread_mutex_unlock(&(fork->mutex));
	}
	return (0);
}

int	take_leftfirst(t_philo *philo)
{
	take_fork(philo->left_fork);
	printf("%d %d has taken a fork\n", \
			diff_time(philo->info->s_time), philo->num);
	take_fork(philo->right_fork);
	printf("%d %d has taken a fork\n", \
			diff_time(philo->info->s_time), philo->num);
	return (0);
}

int	take_rightfirst(t_philo *philo)
{
	take_fork(philo->right_fork);
	printf("%d %d has taken a fork\n", \
			diff_time(philo->info->s_time), philo->num);
	take_fork(philo->left_fork);
	printf("%d %d has taken a fork\n", \
			diff_time(philo->info->s_time), philo->num);
	return (0);
}

int	free_fork(t_philo *philo)
{
	philo->left_fork->state = 1;
	philo->right_fork->state = 1;
	return (0);
}
