/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:27:35 by dham              #+#    #+#             */
/*   Updated: 2023/01/07 19:30:40 by dham             ###   ########.fr       */
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

int	re_in_set(t_strnode *red_node, int fork)
{
	int	fd;
	char	*filename;

	filename = filename_expansion(red_node->str);
	if (!filename)
		return (ambiguous_error(red_node->str, fork));
	if (red_node->type == RE_IN)
	{
		fd = open(red_node->str, O_RDONLY);
		if (fd < 0)
			return (redi_error(red_node->str, fork));
		input_set(fd);
	}
	else if (red_node->type == RE_HEREDOC)
	{
		input_set((int)red_node->str);
	}
	free(filename);
	return (1);
}

int	re_out_set(t_strnode *red_node, int fork)
{
	int		fd;
	char	*filename;

	filename = filename_expansion(red_node->str);
	if (!filename)
		return (ambiguous_error(red_node->str, fork));
	if (red_node->type == RE_OUT)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd < 0)
			return (redi_error(filename, fork));
		output_set(fd);
	}
	else if (red_node->type == RE_APPEND)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (fd < 0)
			return (redi_error(filename, fork));
		output_set(fd);
	}
	free(filename);
	return (1);
}

int	redirect_set(t_astnode *node, int fork)
{
	t_strnode	*red_node;
	int			fd;

	red_node = node->redi.prenode.next;
	while (red_node)
	{
		if (red_node->type == RE_OUT || red_node->type == RE_APPEND)
		{
			if (!re_out_set(red_node, fork))
				return (0);
		}
		else if (red_node->type == RE_IN || red_node->type == RE_HEREDOC)
		{
			if (!re_in_set(red_node, fork))
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