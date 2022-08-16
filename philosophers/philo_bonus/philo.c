/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:24:34 by dham              #+#    #+#             */
/*   Updated: 2022/08/16 17:00:30 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_info	info;
	sem_t	*fork_sem;

	if (argc < 5 || argc > 6 || info_set(argc, argv, &info) < 0)
		return (argerr_print());
	fork_sem = sem_open("fork_sem", O_CREAT | O_EXCL, 0644, info.n_philoshphers);
	sem_unlink("fork_sem");
	make_philo(&info, fork_sem);
	sem_close(fork_sem);
	return (0);
}

int	make_philo(t_info *info, sem_t *fork_sem)
{
	int		i;
	pid_t	*philo;

	philo = malloc(sizeof(pid_t) * info->n_philoshphers);
	gettimeofday(&(info->s_time), NULL);
	i = 0;
	while(i < info->n_philoshphers)
	{
		philo[i] = fork();
		if (philo[i] == 0)
			philo_behavior(i + 1, info, fork_sem);
		else
			continue ;
	}
	while(i < info->n_philoshphers)
		waitpid(philo[i], NULL, 0);
	free(philo);
	return (0);
}

int	philo_behavior(int num, t_info *info, sem_t *fork_sem)
{
	monitoring(info);
	while (1)
	{
		take_fork(info, fork_sem, num);
		eat(info, fork_sem, num);
		sleep_philo(info, num);
	}
	exit(0);
}