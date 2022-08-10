/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:32:35 by dham              #+#    #+#             */
/*   Updated: 2022/08/10 19:23:36 by dham             ###   ########.fr       */
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
