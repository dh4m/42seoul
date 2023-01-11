/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:38:59 by dham              #+#    #+#             */
/*   Updated: 2023/01/11 16:26:15 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include "libft.h"
#include "../minishell.h"
#include <stdio.h>

static int	is_n_op(char *str)
{
	if (*str != '-')
		return (0);
	str++;
	while (*str)
	{
		if (*str != 'n')
			return (0);
		str++;
	}
	return (1);
}

int	ft_echo(char *str)
{
	printf("%s", str);
	return (0);
}

int	exe_echo(char **argv)
{
	int	n_op;
	int	i;

	n_op = 0;
	if (argv[1] && is_n_op(argv[1]))
		n_op = 1;
	i = n_op + 1;
	while (argv[i])
	{
		ft_echo(argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	if (!n_op)
		printf("\n");
	g_info.ret_val = 0;
	return (0);
}
