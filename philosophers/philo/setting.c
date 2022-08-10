/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:43:42 by dham              #+#    #+#             */
/*   Updated: 2022/08/10 19:49:35 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	info_set(int argc, char *argv[], t_info *info)
{
	info->n_philoshphers = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->each_must_eat = ft_atoi(argv[5]);
		if (info->each_must_eat < 0)
			return (-1);
	}
	else
		info->each_must_eat = -1;
	if (valid_arg(info) < 0)
		return (-1);
	return (0);
}

int	fork_set(t_info *info, t_fork *fork)
{
	int	i;

	i = 0;
	while (i < info->n_philoshphers)
	{
		pthread_mutex_init(&(fork[i].mutex), NULL);
		fork[i].num = i + 1;
		i++;
	}
	return (0);
}

int	philo_set(t_info *info, t_fork *fork, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->n_philoshphers)
	{
		philo[i].time_eat = 0;
		philo[i].last_eat = 0;
		philo[i].info = info;
		philo[i].num = i + 1;
		if (i == 0)
			philo[i].left_fork = &(fork[info->n_philoshphers - 1]);
		else
			philo[i].left_fork = &(fork[i - 1]);
		philo[i].right_fork = &(fork[i]);
		i++;
	}
	return (0);
}
