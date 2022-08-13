/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:56:28 by dham              #+#    #+#             */
/*   Updated: 2022/08/13 16:13:09 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	start_monitoring(t_info *info, t_philo *philo)
{
	struct timeval	now;
	int				i;

	gettimeofday(&(info->s_time), NULL);
	info->all_ready = 1;
	while (1)
	{
		gettimeofday(&now, NULL);
		i = -1;
		while (++i < info->n_philoshphers)
		{
			if (check_death(now, &(philo[i]), info->die) < 0 && \
				print_die(now, &(philo[i])))
				return (0);
		}
		i = -1;
		while (info->each_must_eat > 0 && ++i < info->n_philoshphers)
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

int	check_death(struct timeval now, t_philo *philo, int time_to_die)
{
	int	starve;

	starve = diff_time(now, philo->info->s_time) / 1000 - philo->last_eat;
	if (starve > time_to_die)
		return (-1);
	return (0);
}

int	check_all_eat(int must_eat, t_philo *philo)
{
	if (must_eat > philo->time_eat)
		return (-1);
	return (0);
}

int	print_die(struct timeval now, t_philo *philo)
{
	printf("%d %d died\n", diff_time(now, philo->info->s_time) / 1000, \
		philo->num);
	return (1);
}
