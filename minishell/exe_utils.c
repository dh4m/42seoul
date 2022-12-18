/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:27:35 by dham              #+#    #+#             */
/*   Updated: 2022/12/18 16:23:15 by dham             ###   ########.fr       */
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

void	re_in_set(t_astnode *node)
{
	t_strnode	*red_node;
	int			fd;

	red_node = node->redi_i.prenode.next;
	while (red_node)
	{
		if (red_node->type == RE_IN)
		{
			fd = open(red_node->str, O_RDONLY);
			if (fd < 0)
				;//error
			input_set(fd);
		}
		else if (red_node->type == RE_HEREDOC)
		{
			input_set((int)red_node->str);
		}
		red_node = red_node->next;
	}
}

void	re_out_set(t_astnode *node)
{
	t_strnode	*red_node;
	int			fd;

	red_node = node->redi_o.prenode.next;
	while (red_node)
	{
		if (red_node->type == RE_OUT)
		{
			fd = open(red_node->str, O_WRONLY | O_CREAT | O_TRUNC, 0666);
			if (fd < 0)
				;//error
			output_set(fd);
		}
		else if (red_node->type == RE_APPEND)
		{
			fd = open(red_node->str, O_WRONLY | O_CREAT | O_APPEND, 0666);
			if (fd < 0)
				;//error
			output_set(fd);
		}
		red_node = red_node->next;
	}
}
