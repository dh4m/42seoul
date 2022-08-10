/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:56:28 by dham              #+#    #+#             */
/*   Updated: 2022/08/10 19:21:27 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	start_monitoring(t_info *info, t_philo *phlio_list)
{
	pthread_t		monitor_tid;
	t_monitorarg	*m_arg;

	m_arg = malloc(sizeof(t_monitorarg));
	m_arg->info = info;
	m_arg->philo = phlio_list;
	pthread_create(&monitor_tid, NULL, monitor, m_arg);
	pthread_join(monitor_tid, NULL);
	free(m_arg);
	return (0);
}

void	*monitor(void *arg)
{
	t_info *const	info = ((t_monitorarg *)arg)->info;
	t_philo *const	philo = ((t_monitorarg *)arg)->philo;
	struct timeval	now;
	int				i;

	while (1)
	{
		gettimeofday(&now, NULL);
		i = -1;
		while (++i < info->n_philoshphers)
		{
			if (check_death(now, &(philo[i]), info->die) < 0 && \
				print_die(now, philo))
				return (0);
		}
		i = -1;
		while (++i < info->n_philoshphers && info->each_must_eat > 0)
		{
			if (check_all_eat(info->each_must_eat, &(philo[i])) < 0)
				break ;
		}
		if (i == info->n_philoshphers)
			return (0);
	}
}

int	check_death(struct timeval now, t_philo *philo, int time_to_die)
{
	int	starve;

	starve = diff_time(now, philo->s_time) - philo->last_eat;
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
	printf("%d %d is died\n", diff_time(now, philo->s_time), \
		philo->num);
	return (1);
}
