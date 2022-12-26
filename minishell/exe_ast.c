/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_ast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:24:59 by dham              #+#    #+#             */
/*   Updated: 2022/12/26 17:39:26 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include "builtin/ft_builtin.h"
#include "signal/ft_signal.h"
#include "minishell.h"

void	exe_ast(t_astnode *node, int input, int output)
{
	if (!node)
		return ;
	ft_excute_signal_set();
	if (node->type == CMD || node->type == BRACKET_OPEN) // bracket 들어온 것 처리
	{
		exe_pure_cmd(node);
	}
	else if (node->type == PIPE)
	{
		exe_ast_pipe(node->left, node->right, 0);
	}
	else if (node->type == AND)
	{
		exe_ast_and(node->left, node->right);
	}
	else if (node->type == OR)
	{
		exe_ast_or(node->left, node->right);;
	}
	ft_readline_signal_set();
}