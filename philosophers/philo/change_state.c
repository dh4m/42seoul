/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:19:28 by dham              #+#    #+#             */
/*   Updated: 2022/08/13 13:34:26 by dham             ###   ########.fr       */
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
	timestamp = diff_time(tv, philo->info->s_time);
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
	}
}
