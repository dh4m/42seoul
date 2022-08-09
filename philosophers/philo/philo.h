/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:24:45 by dham              #+#    #+#             */
/*   Updated: 2022/08/09 15:55:57 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include<pthread.h>

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
	pthread_mutex_t	mutex_list;
	int				num;
}	t_fork;

typedef struct s_philo
{
	pthread_t	thread;
	int			num;
}	t_philo;




int	argerr_print(void);
int	ft_atoi(const char *str);
int	info_set(int argc, char *argv[], t_info *info);
int	fork_set(t_info *info, t_fork *fork);


#endif