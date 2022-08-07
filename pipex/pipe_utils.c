/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:15:50 by dham              #+#    #+#             */
/*   Updated: 2022/07/20 11:48:14 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void	input_set(int input_fd)
{
	if (dup2(input_fd, 0) == -1)
		error_exit();
	if (close(input_fd) == -1)
		error_exit();
}

static void	output_set_module(int output_fd)
{
	if (dup2(output_fd, 1) == -1)
		error_exit();
	if (close(output_fd) == -1)
		error_exit();
}

void	output_set(const t_argument info, int outfd, int outfile, int step)
{
	if (step == info.argc - 4)
		output_set_module(outfile);
	else
		output_set_module(outfd);
}
