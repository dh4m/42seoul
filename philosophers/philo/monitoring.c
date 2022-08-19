/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:56:28 by dham              #+#    #+#             */
/*   Updated: 2022/08/19 17:06:20 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include <stdio.h>

int	start_monitoring(t_info *info, t_philo *philo)
{
	int				i;

	gettimeofday(&(info->s_time), NULL);
	info->all_ready = 1;
	while (1)
	{
		i = -1;
		while (++i < info->n_philoshphers)
		{
			if (check_death(&(philo[i]), info->die) < 0 && \
				print_die(&(philo[i])) && !--info->all_ready)
				return (0);
		}
		i = -1;
		while (info->each_must_eat > 0 && ++i < info->n_philoshphers)
		{
			if (check_all_eat(info->each_must_eat, &(philo[i])) < 0)
				break ;
		}
		if (i == info->n_philoshphers && !--info->all_ready)
			return (0);
		usleep(200);
	}
	return (0);
}

int	check_death(t_philo *philo, int time_to_die)
{
	int	starve;

	starve = diff_time(philo->info->s_time) - philo->last_eat;
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

int	print_die(t_philo *philo)
{
	printf("%d %d died\n", diff_time(philo->info->s_time), \
		philo->num);
	return (1);
}
