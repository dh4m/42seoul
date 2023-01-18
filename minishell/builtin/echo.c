/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:38:59 by dham              #+#    #+#             */
/*   Updated: 2023/01/18 16:56:21 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include "libft.h"
#include "../minishell.h"
#include <stdio.h>
#include <unistd.h>

static int	is_n_op(char **argv)
{
	int	op_num;
	int	i;

	op_num = 1;
	while (argv[op_num])
	{
		if (argv[op_num][0] != '-')
			return (op_num - 1);
		i = 1;
		while (argv[op_num][i])
		{
			if (argv[op_num][i] != 'n')
				return (op_num - 1);
			i++;
		}
		op_num++;
	}
	return (op_num - 1);
}

int	ft_echo(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

int	exe_echo(char **argv)
{
	int	n_op;
	int	i;

	n_op = 0;
	if (argv[1])
		n_op = is_n_op(argv);
	i = n_op + 1;
	while (argv[i])
	{
		ft_echo(argv[i]);
		if (argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!n_op)
		write(1, "\n", 1);
	g_info.ret_val = 0;
	return (0);
}
