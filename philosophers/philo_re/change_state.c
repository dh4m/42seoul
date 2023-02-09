/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:19:28 by dham              #+#    #+#             */
/*   Updated: 2023/02/09 20:23:32 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	eat(t_philo *philo)
{
	struct timeval	tv;

	pthread_mutex_lock(&philo->info->last_m);
	philo->last_eat = diff_time(philo->info->s_time);
	pthread_mutex_unlock(&philo->info->last_m);
	if (!mutex_print("%d %d is eating\n", philo->num, philo->info))
		return (-1);
	pthread_mutex_lock(&philo->info->eat_m);
	if (++philo->time_eat >= philo->info->each_must_eat && \
		philo->info->each_must_eat > 0)
	{
		pthread_mutex_unlock(&philo->info->eat_m);
		gettimeofday(&tv, NULL);
		delay_time(philo->info->eat, tv);
		drop_forks(philo);
		return (-1);
	}
	pthread_mutex_unlock(&philo->info->eat_m);
	gettimeofday(&tv, NULL);
	delay_time(philo->info->eat, tv);
	drop_forks(philo);
	return (0);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_fork->state = 1;
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_fork->state = 1;
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

int	sleep_philo(t_philo *philo)
{
	struct timeval	tv;

	if (!mutex_print("%d %d is sleeping\n", philo->num, philo->info))
		return (-1);
	gettimeofday(&tv, NULL);
	delay_time(philo->info->sleep, tv);
	if (!mutex_print("%d %d is thinking\n", philo->num, philo->info))
		return (-1);
	if (philo->info->n_philoshphers % 2)
		usleep(500);
	return (0);
}
