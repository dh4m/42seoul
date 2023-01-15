/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_fd_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:35:57 by dham              #+#    #+#             */
/*   Updated: 2023/01/15 20:00:02 by dham             ###   ########.fr       */
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

int	re_in_set_fd(t_strnode *red_node)
{
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
	if (red_node->type == RE_OUT || red_node->type == RE_APPEND)
	{
		output_set(red_node->content.fd);
	}
	return (1);
}

int	io_fd_set(t_astnode *node, int fork)
{
	t_strnode	*red_node;
	int			fd;

	red_node = node->redi.prenode.next;
	while (red_node)
	{
		if (red_node->type == RE_OUT || red_node->type == RE_APPEND)
		{
			re_out_set_fd(red_node);
		}
		else if (red_node->type == RE_IN || red_node->type == RE_HEREDOC \
				|| red_node->type == RE_HEREDOC_EXPAND)
		{
			if (!re_in_set_fd(red_node, fork))#####
				return (0);
		}
		red_node = red_node->next;
	}
	return (1);
}