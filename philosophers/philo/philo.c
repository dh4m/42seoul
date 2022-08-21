/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:24:34 by dham              #+#    #+#             */
/*   Updated: 2022/08/21 12:24:31 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
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
	if (fork_set(&info, fork_list) < 0)
		return (0);
	philo_list = malloc(sizeof(t_philo) * info.n_philoshphers);
	if (philo_set(&info, fork_list, philo_list) < 0)
		return (0);
	i = -1;
	while (++i < info.n_philoshphers)
		pthread_create(&(philo_list[i].thread), NULL, \
						philo_behavior, &philo_list[i]);
	start_monitoring(&info, philo_list);
	i = -1;
	while (++i < info.n_philoshphers)
		pthread_join(philo_list[i].thread, NULL);
	free_mutex(fork_list, info.n_philoshphers);
	free(fork_list);
	free(philo_list);
	return (0);
}

void	*philo_behavior(void *arg)
{
	t_philo *const	philo = arg;

	while (!philo->info->all_ready)
		continue ;
	while (philo->info->all_ready)
	{
		if (philo->num % 2)
		{
			if (philo->last_eat == 0)
				usleep(800);
			take_leftfirst(philo);
		}
		else
			take_rightfirst(philo);
		if (eat(philo) < 0)
			return (0);
		if (sleep_philo(philo) < 0)
			return (0);
	}
	return (0);
}

int	free_mutex(t_fork *fork_list, int fork_num)
{
	int	i;

	i = 0;
	while (i < fork_num)
	{
		pthread_mutex_destroy(&(fork_list[i].mutex));
		i++;
	}
	return (0);
}
