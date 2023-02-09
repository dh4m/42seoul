/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:32:35 by dham              #+#    #+#             */
/*   Updated: 2023/02/09 20:37:22 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include <stdio.h>

int	argerr_print(void)
{
	const char	*err_msg = "wrong argument\n";

	write(2, err_msg, 15);
	return (-1);
}

int	valid_arg(t_info *info)
{
	if (info->n_philoshphers <= 0 || \
		info->die < 0 || \
		info->eat < 0 || \
		info->sleep < 0)
		return (-1);
	return (0);
}

int	diff_time(struct timeval start)
{
	struct timeval	last;

	gettimeofday(&last, NULL);
	return ((last.tv_sec - start.tv_sec) * 1000 \
			+ (last.tv_usec / 1000 - start.tv_usec / 1000));
}

void	delay_time(int msec, struct timeval start)
{
	usleep(msec * 800);
	while (diff_time(start) < msec)
		usleep(200);
	return ;
}

int	mutex_print(char *str, int num, t_info *info)
{
	pthread_mutex_lock(&info->ready_m);
	if (!info->all_ready)
	{
		pthread_mutex_unlock(&info->ready_m);
		return (0);
	}
	pthread_mutex_unlock(&info->ready_m);
	pthread_mutex_lock(&info->print_m);
	printf(str, diff_time(info->s_time), num);
	pthread_mutex_unlock(&info->print_m);
	return (1);
}
