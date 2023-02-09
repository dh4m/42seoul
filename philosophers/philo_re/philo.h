/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:24:45 by dham              #+#    #+#             */
/*   Updated: 2023/02/09 21:18:54 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				n_philoshphers;
	int				die;
	int				eat;
	int				sleep;
	int				each_must_eat;
	struct timeval	s_time;
	int				all_ready;
	int				print_able;
	pthread_mutex_t	print_m;
	pthread_mutex_t	ready_m;
	pthread_mutex_t	last_m;
	pthread_mutex_t	eat_m;
}	t_info;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				state;
}	t_fork;

typedef struct s_philo
{
	t_info			*info;
	pthread_t		thread;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int				num;
	int				time_eat;
	int				last_eat;
}	t_philo;

void	*philo_behavior(void *arg);
int		free_mutex(t_fork *fork_list, int fork_num, t_info *info);

int		argerr_print(void);
int		valid_arg(t_info *info);
int		diff_time(struct timeval start);
void	delay_time(int msec, struct timeval start);
int		mutex_print(char *str, int num, t_info *info);

int		ft_atoi(const char *str);

int		info_set(int argc, char *argv[], t_info *info);
int		fork_set(t_info *info, t_fork *fork);
int		philo_set(t_info *info, t_fork *fork, t_philo *philo);

int		take_leftfirst(t_philo *philo);
int		take_rightfirst(t_philo *philo);

int		eat(t_philo *philo);
int		sleep_philo(t_philo *philo);
void	drop_forks(t_philo *philo);

int		start_monitoring(t_info *info, t_philo *philo);
int		check_death(t_philo *philo, int time_to_die);
int		check_all_eat(int must_eat, t_philo *philo);
int		print_die(int num, t_info *info);

#endif