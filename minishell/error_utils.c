/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:32:09 by dham              #+#    #+#             */
/*   Updated: 2022/12/22 15:26:11 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "builtin/ft_builtin.h"
#include "signal/ft_signal.h"
#include "minishell.h"
#include <fcntl.h>

int	syntax_error(int ret_val)
{
	g_info.ret_val = 258;
	ft_putstr_fd("Syntax error\n", 2);
	return (ret_val);
}

int	node_syntax_error(int ret_val, t_astnode *need_free)
{
	if (need_free)
		clear_ast(need_free);
	return (syntax_error(ret_val));
}

int	node_return(int ret_val, t_astnode *need_free)
{
	if (need_free)
		clear_ast(need_free);
	return (ret_val);
}

void	redi_error(char *name)
{
	char	*err_str;

	err_str = ft_strjoin("minishell: ", name);
	perror(err_str);
	free(err_str);
	exit (1);
}