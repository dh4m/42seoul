/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:42:25 by dham              #+#    #+#             */
/*   Updated: 2022/08/23 12:46:58 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	take_fork(t_info *info, sem_t *fork_sem)
{
	if (info->num % 2 == 0 && info->time_eat == 0)
	{
		printf("%d %d has taken a fork\n%d %d has taken a fork\n", \
				diff_time(info->s_time), info->num, \
				diff_time(info->s_time), info->num);
		return (0);
	}
	sem_wait(fork_sem);
	sem_print("%d %d has taken a fork\n", info->num, info);
	sem_wait(fork_sem);
	sem_print("%d %d has taken a fork\n", info->num, info);
	return (0);
}
