/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:38:59 by dham              #+#    #+#             */
/*   Updated: 2022/12/23 14:18:02 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include "libft.h"
#include "../minishell.h"
#include <stdio.h>

int	ft_echo(char *str)
{
	printf("%s ", str);
	return (0);
}

int	exe_echo(char **argv)
{
	int	n_op;
	int	i;

	n_op = 0;
	if (ft_strncmp(argv[1], "-n", 3) == 0)
		n_op = 1;
	i = n_op + 1;
	while (argv[i])
	{
		ft_echo(argv[i]);
		i++;
	}
	if (!n_op)
		printf("\n");
	g_info.ret_val = 0;
	return (0);
}