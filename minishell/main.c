/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:59:02 by dham              #+#    #+#             */
/*   Updated: 2023/01/19 18:17:27 by dham             ###   ########.fr       */
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

static int	is_space_str(char *str);
static void	start_ascii_art(int argc, char *argv[]);

int	main(int argc, char *argv[], char *envp[])
{
	char	*str;

	start_ascii_art(argc, argv);
	ft_readline_signal_set();
	turn_off_show_signal();
	info_init(envp);
	while (1)
	{
		str = readline("minishell$ ");
		if (str && !is_space_str(str) && *str != 0)
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

static void	start_ascii_art(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	;
}

static int	is_space_str(char *str)
{
	while (*str)
	{
		if (*str != '\t' && *str != '\n' && *str != '\r' && *str != ' ' \
			&& *str != '\v' && *str != '\f')
			return (0);
		str++;
	}
	return (1);
}
