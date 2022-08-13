/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:24:34 by dham              #+#    #+#             */
/*   Updated: 2022/08/13 13:25:03 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_info	info;
	t_fork	*fork_list;
	t_philo	*philo_list;
	int		i;

	if (argc < 5 || argc > 6 || info_set(argc, argv, &info) < 0)
		return (argerr_print());
	fork_list = malloc(sizeof(t_fork) * info.n_philoshphers);
	fork_set(&info, fork_list);
	philo_list = malloc(sizeof(t_philo) * info.n_philoshphers);
	philo_set(&info, fork_list, philo_list);
	i = -1;
	while (++i < info.n_philoshphers)
	{
		pthread_create(&(philo_list[i].thread), NULL, \
						philo_behavior, &philo_list[i]);
		pthread_detach(philo_list[i].thread);
	}
	start_monitoring(&info, philo_list);
	free(fork_list);
	free(philo_list);
	return (0);
}

void	*philo_behavior(void *arg)
{
	t_philo *const	philo = arg;

	while(!philo->info->all_ready)
		continue;
	while (1)
	{
		if (philo->num % 2)
		{
			if (philo->last_eat == 0)
				usleep(100);
			take_leftfirst(philo);
		}
		else
			take_rightfirst(philo);
		change_state(philo, EAT);
		free_fork(philo);
		change_state(philo, SLEEP);
		change_state(philo, THINKING);
	}
	return (0);
}
