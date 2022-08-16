/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:04:35 by dham              #+#    #+#             */
/*   Updated: 2022/08/16 16:03:00 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	take_fork(t_info *info, sem_t *fork_sem, int num)
{
	struct timeval	tv;

	sem_wait(fork_sem);
	gettimeofday(&tv, NULL);
	printf("%d %d has taken a fork\n", \
			diff_time(tv, info->s_time), num);
	sem_wait(fork_sem);
	gettimeofday(&tv, NULL);
	printf("%d %d has taken a fork\n", \
			diff_time(tv, info->s_time), num);
	return (0);
}

int	free_fork(sem_t *fork_sem)
{
	sem_wait(fork_sem);
	sem_wait(fork_sem);
	return (0);
}

int	eat(t_info *info, sem_t *fork_sem, int num)
{
	struct timeval	tv;

	info->last_eat = diff_time(info->s_time);
	printf("%d %d is eating\n", diff_time(info->s_time), \
			num);
	info->time_eat++;
	gettimeofday(&tv, NULL);
	delay_time(info->eat, tv);
	sem_post(fork_sem);
	sem_post(fork_sem);
	return (0);
}

int	sleep_philo(t_info *info, int num)
{
	struct timeval	tv;

	printf("%d %d is sleeping\n", diff_time(info->s_time), \
			num);
	gettimeofday(&tv, NULL);
	delay_time(info->sleep, tv);
	printf("%d %d is thinking\n", diff_time(info->s_time), \
			num);
	return (0);
}