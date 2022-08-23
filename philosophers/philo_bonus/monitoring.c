/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:37:11 by dham              #+#    #+#             */
/*   Updated: 2022/08/23 12:52:26 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

int	start_monitoring(t_info *info)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, monitoring, info);
	pthread_detach(monitor);
	return (0);
}

void	*monitoring(void *arg)
{
	t_info *const	info = arg;
	int				starve;

	while (1)
	{
		starve = diff_time(info->s_time) - info->last_eat;
		if (starve > info->die)
			print_die(info);
		usleep(1000);
	}
	return (0);
}

int	print_die(t_info *info)
{
	sem_wait(info->print_sem);
	printf("%d %d died\n", diff_time(info->s_time), \
		info->num);
	kill(0, SIGKILL);
	exit(0);
}
