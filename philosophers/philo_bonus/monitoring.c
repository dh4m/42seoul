/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:37:11 by dham              #+#    #+#             */
/*   Updated: 2022/08/16 16:07:23 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

int	start_monitoring(t_info *info)
{
	pthread_t	monitor;

	pthread_create(&monitor, NULL, monitoring, info);
}

void	*monitoring(void *arg)
{
	
}