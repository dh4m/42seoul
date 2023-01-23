/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:49:14 by dham              #+#    #+#             */
/*   Updated: 2023/01/23 15:28:05 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ft_signal.h"
#include "../minishell.h"

void	ft_readline_signal_set(void)
{
	signal(SIGINT, readline_proc);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_excute_signal_set(void)
{
	signal(SIGINT, newline_proc);
	signal(SIGQUIT, newline_proc);
}

void	ft_default_signal_set(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	ft_heredoc_signal_set(void)
{
	rl_event_hook = empty_event;
	signal(SIGINT, heredoc_sig_proc);
	signal(SIGQUIT, readline_proc);
}

void	end_heredoc_set(void)
{
	rl_event_hook = 0;
	rl_done = 0;
	ft_readline_signal_set();
}
