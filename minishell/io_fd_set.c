/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_fd_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:35:57 by dham              #+#    #+#             */
/*   Updated: 2023/01/18 19:56:38 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include "libft.h"
#include "builtin/ft_builtin.h"
#include "signal/ft_signal.h"
#include "minishell.h"

void	input_set(int input)
{
	dup2(input, 0);
	if (input != STDIN_FILENO)
		close(input);
}

void	output_set(int output)
{
	dup2(output, 1);
	if (output != STDOUT_FILENO)
		close(output);
}

int	re_in_set_fd(t_strnode *red_node)
{
	if (red_node->content.fd < 0)
		return (0);
	if (red_node->type == RE_IN || red_node->type == RE_HEREDOC)
	{
		input_set(red_node->content.fd);
	}
	else if (red_node->type == RE_HEREDOC_EXPAND)
	{
		input_set(expansion_heredoc_file(red_node->content.fd));
	}
	return (1);
}

int	re_out_set_fd(t_strnode *red_node)
{
	if (red_node->content.fd < 0)
		return (0);
	output_set(red_node->content.fd);
	return (1);
}

int	io_fd_set(t_astnode *node)
{
	t_strnode	*red_node;
	int			fd;

	red_node = node->redi.prenode.next;
	while (red_node)
	{
		if (red_node->type == RE_OUT || red_node->type == RE_APPEND)
		{
			if (!re_out_set_fd(red_node))
				return (0);
		}
		else if (red_node->type == RE_IN || red_node->type == RE_HEREDOC \
				|| red_node->type == RE_HEREDOC_EXPAND)
		{
			if (!re_in_set_fd(red_node))
				return (0);
		}
		red_node = red_node->next;
	}
	return (1);
}
