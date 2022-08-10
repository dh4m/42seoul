/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:19:28 by dham              #+#    #+#             */
/*   Updated: 2022/08/10 19:41:40 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	change_state(t_philo *philo, int state)
{
	struct timeval	tv;
	static char		*state_str = NULL;

	if (state == EAT)
		state_str = "is eating";
	else if (state == SLEEP)
		state_str = "is sleeping";
	else if (state == THINKING)
		state_str = "is thinking";
	gettimeofday(&tv, NULL);
	printf("%d %d %s\n", diff_time(tv, philo->s_time), philo->num, state_str);
	if (state == EAT)
	{
		philo->last_eat = diff_time(tv, philo->s_time);
		philo->time_eat++;
		usleep(philo->info->eat * 1000);
	}
	else if (state == SLEEP)
		usleep(philo->info->sleep * 1000);
}
