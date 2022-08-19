/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:04:35 by dham              #+#    #+#             */
/*   Updated: 2022/08/19 17:02:47 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	eat(t_info *info, sem_t *fork_sem)
{
	struct timeval	tv;

	info->last_eat = diff_time(info->s_time);
	printf("%d %d is eating\n", info->last_eat, \
			info->num);
	if (info->each_must_eat <= ++info->time_eat && \
		info->each_must_eat > 0)
		finish_eat(fork_sem);
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

	printf("%d %d is sleeping\n", diff_time(info->s_time), \
			info->num);
	gettimeofday(&tv, NULL);
	delay_time(info->sleep, tv);
	printf("%d %d is thinking\n", diff_time(info->s_time), \
			info->num);
	return (0);
}
