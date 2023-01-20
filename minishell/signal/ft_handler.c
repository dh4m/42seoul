/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:46:32 by dham              #+#    #+#             */
/*   Updated: 2023/01/20 17:02:14 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
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
		return ;
	}
	else if (sig == SIGQUIT)
	{
		return ;
	}
}

void	recieve_signal(int sig)
{
	const int	sig_exit_code = WTERMSIG(sig);

	g_info.ret_val = sig_exit_code + 128;
	if (sig_exit_code == SIGINT)
		printf("\n");
	else if (sig_exit_code == SIGQUIT)
		printf("Quit: %d\n", SIGQUIT);
}

void	readline_proc(int sig)
{
	if (sig == SIGINT)
	{
		g_info.ret_val = 1;
		printf("\n");
		printf("\033[1;31m");
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
