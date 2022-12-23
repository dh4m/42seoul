/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:55:13 by dham              #+#    #+#             */
/*   Updated: 2022/12/23 14:21:14 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include "libft.h"
#include "../minishell.h"
#include <unistd.h>
#include <stdlib.h>

static int	ft_isnum(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

static void	exit_error(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("exit: '", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': numeric argument required\n", 2);
}

int	ft_exit(int code)
{
	exit(code);
}

int	exe_exit(char **argv, int parents)
{
	if (argv[1] && !ft_isnum(argv[1]))
	{
		if(parents && isatty(1))
			printf("exit\n");
		exit_error(argv[1]);
		g_info.ret_val = 255;
		ft_exit(g_info.ret_val);
	}
	else if (argv[1] && argv[2])
	{
		if(parents && isatty(1))
			printf("exit\n");
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		g_info.ret_val = 1;
		return (0);
	}
	if(parents && isatty(1))
			printf("exit\n");
	if (argv[1])
		ft_exit(ft_atoi(argv[1]));
	else
		ft_exit(g_info.ret_val);
	return (0);
}