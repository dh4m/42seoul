/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:44:55 by dham              #+#    #+#             */
/*   Updated: 2022/08/11 16:42:32 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

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

int	diff_time(struct timeval last, struct timeval start)
{
	return ((last.tv_sec * 1000 - start.tv_sec * 1000) \
			+ (last.tv_usec - start.tv_usec) / 1000);
}

void	delay_time(int msec)
{
	static struct timeval	start;
	static struct timeval	now;

	gettimeofday(&start, NULL);
	while(1)
	{
		gettimeofday(&now, NULL);
		if (diff_time(now, start) >= msec)
			return ;
	}
	return ;
}
