/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:59:02 by dham              #+#    #+#             */
/*   Updated: 2022/09/27 21:03:45 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "builtin/ft_builtin.h"
#include "signal/ft_signal.h"
#include "minishell.h"

t_info	g_info;

int main(int argc, char *argv[], char *envp[])
{
	char *str;
	
	ft_signal_set();
	info_init(envp);
	while (1)
	{
		str = readline("minishell$ ");
		if (str && *str != '\n' && *str != 0)
		{
			proc_cmd(str);
			add_history(str);
		}
		else if (!str)
		{
			printf("\033[1A\033[11Cexit\n");
			exit(g_info.ret_val);
		}
		free(str);
	}
	return (0);
}
