/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:27:35 by dham              #+#    #+#             */
/*   Updated: 2023/01/17 12:52:56 by dham             ###   ########.fr       */
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

int	re_in_set(t_strnode *red_node)
{
	int		fd;
	char	*filename;

	filename = filename_expansion(red_node->content.str);
	if (!filename)
		return (ambiguous_error(red_node->content.str));
	if (red_node->type == RE_IN)
	{
		fd = open(red_node->content.str, O_RDONLY);
		red_node->content.fd = fd;
	}
	if (fd < 0)
	{
		redi_error(filename);
		free(filename);
		return (0);
	}
	free(filename);
	return (1);
}

int	re_out_set(t_strnode *red_node)
{
	int		fd;
	char	*filename;

	filename = filename_expansion(red_node->content.str);
	if (!filename)
		return (ambiguous_error(red_node->content.str));
	if (red_node->type == RE_OUT)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		red_node->content.fd = fd;
	}
	else if (red_node->type == RE_APPEND)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
		red_node->content.fd = fd;
	}
	if (fd < 0)
	{
		redi_error(filename);
		free(filename);
		return (0);
	}
	free(filename);
	return (1);
}

int	redirect_set(t_astnode *node)
{
	t_strnode	*red_node;
	int			fd;

	red_node = node->redi.prenode.next;
	while (red_node)
	{
		if (red_node->type == RE_OUT || red_node->type == RE_APPEND)
		{
			if (!re_out_set(red_node))
				return (0);
		}
		else if (red_node->type == RE_IN)
		{
			if (!re_in_set(red_node))
				return (0);
		}
		red_node = red_node->next;
	}
	return (1);
}

void	redirect_reset(int backup[2])
{
	dup2(backup[0], 0);
	close(backup[0]);
	dup2(backup[1], 1);
	close(backup[1]);
}
