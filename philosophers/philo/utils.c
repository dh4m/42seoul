/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:32:35 by dham              #+#    #+#             */
/*   Updated: 2022/08/09 15:29:10 by dham             ###   ########.fr       */
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

int	info_set(int argc, char *argv[], t_info *info)
{
	info->n_philoshphers = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->each_must_eat = ft_atoi(argv[5]);
		if (info->each_must_eat < 0)
			return (-1);
	else
		info->each_must_eat = -1;
	if (valid_arg(info) < 0)
		reutrn (-1);
	return (0);
}

int	valid_arg(t_info *info)
{
	if (info->n_philoshphers < 0 || \
		info->die < 0 || \
		info->eat < 0 || \
		info->sleep < 0)
		return (-1);
	return (0);
}