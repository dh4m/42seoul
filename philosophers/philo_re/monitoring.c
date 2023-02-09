/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:56:28 by dham              #+#    #+#             */
/*   Updated: 2023/02/09 20:38:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "philo.h"

int	start_monitoring(t_info *info, t_philo *philo)
{
	int				i;

	gettimeofday(&(info->s_time), NULL);
	pthread_mutex_unlock(&info->ready_m);
	while (1)
	{
		i = -1;
		while (++i < info->n_philoshphers)
		{
			if (check_death(&(philo[i]), info->die) < 0 && \
				print_die(philo[i].num, info))
				return (0);
		}
		i = -1;
		while (++i < info->n_philoshphers)
		{
			if (check_all_eat(info->each_must_eat, &(philo[i])) < 0)
				break ;
		}
		if (i == info->n_philoshphers)
			return (0);
		usleep(200);
	}
	return (0);
}

int	check_death(t_philo *philo, int time_to_die)
{
	int	starve;

	if (check_all_eat(philo->info->each_must_eat, philo) == 0)
		return (0);
	starve = diff_time(philo->info->s_time);
	pthread_mutex_lock(&philo->info->last_m);
	starve -= philo->last_eat;
	pthread_mutex_unlock(&philo->info->last_m);
	if (starve > time_to_die)
		return (-1);
	return (0);
}

int	check_all_eat(int must_eat, t_philo *philo)
{
	if (must_eat <= 0)
		return (-1);
	pthread_mutex_lock(&philo->info->eat_m);
	if (must_eat > philo->time_eat)
	{
		pthread_mutex_unlock(&philo->info->eat_m);
		return (-1);
	}
	pthread_mutex_unlock(&philo->info->eat_m);
	return (0);
}

int	print_die(int num, t_info *info)
{
	pthread_mutex_lock(&info->ready_m);
	info->all_ready = 0;
	pthread_mutex_unlock(&info->ready_m);
	pthread_mutex_lock(&info->print_m);
	printf("%d %d died\n", diff_time(info->s_time), num);
	pthread_mutex_unlock(&info->print_m);
	return (1);
}
