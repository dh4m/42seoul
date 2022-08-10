/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:46:41 by dham              #+#    #+#             */
/*   Updated: 2022/08/10 19:47:00 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "philo.h"

int	info_set(int argc, char *argv[], t_info *info)
{
	info->n_philoshphers = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->each_must_eat = ft_atoi(argv[5]);
		if (info->each_must_eat < 0)
			return (-1);
	}
	else
		info->each_must_eat = -1;
	if (valid_arg(info) < 0)
		return (-1);
	return (0);
}