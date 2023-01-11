/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:46:32 by dham              #+#    #+#             */
/*   Updated: 2023/01/11 16:23:43 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ft_signal.h"
#include "../minishell.h"

int	empty_event(void)
{
	return (0);
}

void	newline_proc(int sig)
{
	if (sig == SIGINT)
	{
		g_info.ret_val = 130;
		printf("\n");
	}
	else if (sig == SIGQUIT)
	{
		g_info.ret_val = 131;
		printf("Quit: 3\n");
	}
}

void	readline_proc(int sig)
{
	if (sig == SIGINT)
	{
		g_info.ret_val = 1;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	heredoc_sig_proc(int sig)
{
	if (sig == SIGINT)
	{
		g_info.ret_val = SIGINT_CATCH;
		rl_replace_line("", 1);
		rl_done = 1;
	}
}
