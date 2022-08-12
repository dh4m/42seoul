/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:43:48 by dham              #+#    #+#             */
/*   Updated: 2022/08/12 18:45:45 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <semaphore.h>
# include <sys/time.h>

enum e_state
{
	EAT,
	SLEEP,
	THINKING
};

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
/*
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
*/
int		make_philo(t_info *info, sem_t *fork_sem);
int		philo_behavior(int num, t_info *info, sem_t *fork_sem);

int		argerr_print(void);
int		valid_arg(t_info *info);
int		diff_time(struct timeval last, struct timeval start);
void	delay_time(int msec);

int		info_set(int argc, char *argv[], t_info *info);

int	take_fork(t_info *info, sem_t *fork_sem, int num);
int	free_fork(sem_t *fork_sem);
int	eat();
int	sleep();
int	think();

#endif