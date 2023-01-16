/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:32:09 by dham              #+#    #+#             */
/*   Updated: 2023/01/16 16:10:32 by dham             ###   ########.fr       */
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

char	*token_str(t_cmdnode *node)
{
	const char	*token[11] = {
		"|", "&&", "||", "(", ")", "<", ">>", ">", "<<", "\"", "\'"
	};

	if (!node)
		return ((char *)"newline");
	else if (node->type == CMD)
		return (node->cmd);
	return ((char *)token[node->type]);
}

int	node_syntax_error(int ret_val, t_astnode *need_free, t_cmdnode *node)
{
	g_info.ret_val = 258;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("syntax error near unexpected token \'", 2);
	ft_putstr_fd(token_str(node), 2);
	ft_putstr_fd("\'\n", 2);
	if (need_free)
			clear_ast(need_free);
	return (ret_val);
}

int	node_free_return(int ret_val, t_astnode *need_free)
{
	if (need_free)
		clear_ast(need_free);
	return (ret_val);
}

int	redi_error(char *name)
{
	char	*err_str;

	err_str = ft_strjoin("minishell: ", name);
	perror(err_str);
	free(err_str);
	return (0);
}

int	ambiguous_error(char *name)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ambiguous redirect\n", 2);
	return (0);
}
