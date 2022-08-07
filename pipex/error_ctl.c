/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ctl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:37:14 by dham              #+#    #+#             */
/*   Updated: 2022/07/20 11:48:05 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pipex.h"
#include "libft/libft.h"

void	error_exit(void)
{
	perror("zsh");
	exit(-1);
}

void	command_err(const char *cmd)
{
	ft_putstr_fd("zsh: ", 2);
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd((char *)cmd, 2);
	ft_putstr_fd("\n", 2);
}

void	arg_err(void)
{
	ft_putstr_fd("Too few argument!\n", 2);
	exit(-1);
}
