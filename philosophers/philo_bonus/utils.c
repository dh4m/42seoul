/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:44:55 by dham              #+#    #+#             */
/*   Updated: 2022/08/23 11:25:37 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include <stdlib.h>

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

void	*safealloc(size_t size)
{
	void	*ret_ptr;

	ret_ptr = malloc(size);
	if (!ret_ptr)
		exit(-1);
	return (ret_ptr);
}
