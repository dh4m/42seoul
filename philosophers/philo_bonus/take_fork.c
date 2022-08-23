/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:42:25 by dham              #+#    #+#             */
/*   Updated: 2022/08/23 13:03:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	take_fork(t_info *info, sem_t *fork_sem)
{
	if (info->num % 2 == 0 && info->time_eat == 0)
	{
		sem_print("%d %d has taken a fork\n", info->num, info);
		sem_print("%d %d has taken a fork\n", info->num, info);
		return (0);
	}
	sem_wait(fork_sem);
	sem_print("%d %d has taken a fork\n", info->num, info);
	sem_wait(fork_sem);
	sem_print("%d %d has taken a fork\n", info->num, info);
	return (0);
}
