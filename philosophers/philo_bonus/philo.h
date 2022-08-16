/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:43:48 by dham              #+#    #+#             */
/*   Updated: 2022/08/16 16:03:28 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct s_info
{
	int				n_philoshphers;
	int				die;
	int				eat;
	int				sleep;
	int				each_must_eat;
	struct timeval	s_time;
	int				time_eat;
	int				last_eat;
}	t_info;

int		philo_behavior(int num, t_info *info, sem_t *fork_sem);
int		free_mutex(t_fork *fork_list, int fork_num);

int		argerr_print(void);
int		valid_arg(t_info *info);
int		diff_time(struct timeval start);
void	delay_time(int msec, struct timeval start);

int		ft_atoi(const char *str);

int		info_set(int argc, char *argv[], t_info *info);
int		fork_set(t_info *info, t_fork *fork);
int		philo_set(t_info *info, t_fork *fork, t_philo *philo);

int		take_fork(t_info *info, sem_t *fork_sem, int num);

int		eat(t_info *info, sem_t *fork_sem, int num);
int		sleep_philo(t_info *info, int num);

int		start_monitoring(t_info *info, t_philo *philo);
void	*monitoring(void *arg);
int		check_death(t_philo *philo, int time_to_die);
int		check_all_eat(int must_eat, t_philo *philo);
int		print_die(t_philo *philo);

#endif