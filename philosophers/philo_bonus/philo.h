/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:43:48 by dham              #+#    #+#             */
/*   Updated: 2022/08/19 16:10:20 by dham             ###   ########.fr       */
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
	int				num;
}	t_info;

int		philo_behavior(int num, t_info *info, sem_t *fork_sem);
int		make_philo(t_info *info, sem_t *fork_sem);
void	philo_waitpid(t_info *info, pid_t *philo);

int		argerr_print(void);
int		valid_arg(t_info *info);
int		diff_time(struct timeval start);
void	delay_time(int msec, struct timeval start);
void	*safealloc(size_t size);

int		ft_atoi(const char *str);

int		info_set(int argc, char *argv[], t_info *info);

int		take_fork(t_info *info, sem_t *fork_sem);

int		eat(t_info *info, sem_t *fork_sem);
void	finish_eat(sem_t *fork_sem);
int		sleep_philo(t_info *info);

int		start_monitoring(t_info *info);
void	*monitoring(void *arg);
int		check_death(t_info *info, int time_to_die);
int		print_die(t_info *info);

#endif