/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:19:28 by dham              #+#    #+#             */
/*   Updated: 2022/08/14 19:53:44 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	change_state(t_philo *philo, int state)
{
	struct timeval	tv;
	int				timestamp;

	gettimeofday(&tv, NULL);
	timestamp = diff_time(philo->info->s_time);
	if (state == EAT)
	{
		philo->last_eat = timestamp;
		printf("%d %d is eating\n", timestamp, philo->num);
		philo->time_eat++;
		delay_time(philo->info->eat);
	}
	else if (state == SLEEP)
	{
		printf("%d %d is sleeping\n", timestamp, philo->num);
		delay_time(philo->info->sleep);
	}
	else if (state == THINKING)
	{
		printf("%d %d is thinking\n", timestamp, philo->num);
		if (philo->info->n_philoshphers % 2)
			usleep(100);
	}
}
