/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:24:34 by dham              #+#    #+#             */
/*   Updated: 2022/08/23 12:50:31 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_info	info;
	sem_t	*fork_sem;

	if (argc < 5 || argc > 6 || info_set(argc, argv, &info) < 0)
		return (argerr_print());
	fork_sem = sem_open("fork_sem", O_CREAT | O_EXCL, 0644, \
						info.n_philoshphers % 2);
	info.print_sem = sem_open("print_sem", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("fork_sem");
	sem_unlink("print_sem");
	make_philo(&info, fork_sem);
	sem_close(fork_sem);
	sem_close(info.print_sem);
	return (0);
}

int	make_philo(t_info *info, sem_t *fork_sem)
{
	int		i;
	pid_t	*philo;

	philo = safealloc(sizeof(pid_t) * info->n_philoshphers);
	gettimeofday(&(info->s_time), NULL);
	i = 1;
	while (i < info->n_philoshphers)
	{
		philo[i] = fork();
		if (philo[i] == 0)
			philo_behavior(i + 1, info, fork_sem);
		i += 2;
	}
	i = 0;
	while (i < info->n_philoshphers)
	{
		philo[i] = fork();
		if (philo[i] == 0)
			philo_behavior(i + 1, info, fork_sem);
		i += 2;
	}
	philo_waitpid(info, philo);
	free(philo);
	return (0);
}

int	philo_behavior(int num, t_info *info, sem_t *fork_sem)
{
	info->num = num;
	start_monitoring(info);
	while (1)
	{
		take_fork(info, fork_sem);
		eat(info, fork_sem);
		sleep_philo(info);
	}
	exit(0);
	return (0);
}

void	philo_waitpid(t_info *info, pid_t *philo)
{
	int	i;

	i = 0;
	while (i < info->n_philoshphers)
	{
		waitpid(philo[i], NULL, 0);
		i++;
	}
}

void	sem_print(char *str, int num, t_info *info)
{
	sem_wait(info->print_sem);
	printf(str, diff_time(info->s_time), num);
	sem_post(info->print_sem);
}
