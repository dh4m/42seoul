/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:19:28 by dham              #+#    #+#             */
/*   Updated: 2022/08/21 14:31:18 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

int	eat(t_philo *philo)
{
	struct timeval	tv;

	philo->last_eat = diff_time(philo->info->s_time);
	if (philo->info->all_ready)
		printf("%d %d is eating\n", diff_time(philo->info->s_time), \
				philo->num);
	else
		return (-1);
	if (++philo->time_eat >= philo->info->each_must_eat && \
		philo->info->each_must_eat > 0)
	{
		philo->left_fork->state = 1;
		philo->right_fork->state = 1;
		philo->last_eat = -1;
		return (-1);
	}
	gettimeofday(&tv, NULL);
	delay_time(philo->info->eat, tv);
	philo->left_fork->state = 1;
	philo->right_fork->state = 1;
	return (0);
}

int	sleep_philo(t_philo *philo)
{
	struct timeval	tv;

	if (philo->info->all_ready)
		printf("%d %d is sleeping\n", diff_time(philo->info->s_time), \
				philo->num);
	else
		return (-1);
	gettimeofday(&tv, NULL);
	delay_time(philo->info->sleep, tv);
	if (philo->info->all_ready)
		printf("%d %d is thinking\n", diff_time(philo->info->s_time), \
				philo->num);
	else
		return (-1);
	if (philo->info->n_philoshphers % 2)
		usleep(500);
	return (0);
}
