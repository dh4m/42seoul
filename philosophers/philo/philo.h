/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:24:45 by dham              #+#    #+#             */
/*   Updated: 2022/08/10 19:05:02 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include<pthread.h>
# include <sys/time.h>

enum e_state
{
	EAT, 
	SLEEP,
	THINKING
};

typedef struct s_info
{
	int	n_philoshphers;
	int	die;
	int	eat;
	int	sleep;
	int	each_must_eat;
}	t_info;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				num;
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
	struct timeval	s_time;
}	t_philo;

typedef struct s_monitorarg
{
	t_info	*info;
	t_philo *philo;
}	t_monitorarg;


void	*philo_behavior(void *arg);

int	argerr_print(void);
int	valid_arg(t_info *info);
int	diff_time(struct timeval last, struct timeval start);

int	ft_atoi(const char *str);

int	info_set(int argc, char *argv[], t_info *info);
int	fork_set(t_info *info, t_fork *fork);
int	philo_set(t_info *info, t_fork *fork, t_philo *philo);

int	take_leftfirst(t_philo *philo);
int	take_rightfirst(t_philo *philo);
int	free_fork(t_philo *philo);

void	change_state(t_philo *philo, int state);

int		start_monitoring(t_info *info, t_philo *phlio_list);
void	*monitor(void *arg);
int		check_death(struct timeval now, t_philo *philo, int time_to_die);
int		check_all_eat(int must_eat, t_philo *philo);
int		print_die(struct timeval now, t_philo *philo);


#endif