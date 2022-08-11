/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:24:34 by dham              #+#    #+#             */
/*   Updated: 2022/08/11 19:52:02 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 5 || argc > 6 || info_set(argc, argv, &info) < 0)
		return (argerr_print());
	
	return (0);
}

int	make_philo()
{
	
}
