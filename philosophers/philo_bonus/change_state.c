/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:04:35 by dham              #+#    #+#             */
/*   Updated: 2022/08/23 12:48:25 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	eat(t_info *info, sem_t *fork_sem)
{
	struct timeval	tv;

	info->last_eat = diff_time(info->s_time);
	sem_print("%d %d is eating\n", info->num, info);
	if (info->each_must_eat <= ++info->time_eat && \
		info->each_must_eat > 0)
	{
		gettimeofday(&tv, NULL);
		delay_time(info->eat, tv);
		finish_eat(fork_sem);
	}
	gettimeofday(&tv, NULL);
	delay_time(info->eat, tv);
	sem_post(fork_sem);
	sem_post(fork_sem);
	return (0);
}

void	finish_eat(sem_t *fork_sem)
{
	sem_post(fork_sem);
	sem_post(fork_sem);
	exit(0);
}

int	sleep_philo(t_info *info)
{
	struct timeval	tv;

	sem_print("%d %d is sleeping\n", info->num, info);
	gettimeofday(&tv, NULL);
	delay_time(info->sleep, tv);
	sem_print("%d %d is thinking\n", info->num, info);
	return (0);
}
