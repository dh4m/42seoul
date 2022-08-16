/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:42:25 by dham              #+#    #+#             */
/*   Updated: 2022/08/16 16:06:45 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_info *info, sem_t *fork_sem, int num)
{
	sem_wait(fork_sem);
	printf("%d %d has taken a fork\n", \
			diff_time(info->s_time), num);
	sem_wait(fork_sem);
	printf("%d %d has taken a fork\n", \
			diff_time(info->s_time), num);
	return (0);
}