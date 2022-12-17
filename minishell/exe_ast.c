/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_ast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:24:59 by dham              #+#    #+#             */
/*   Updated: 2022/12/17 21:35:25 by dham             ###   ########.fr       */
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
	if (node->type == CMD || node->type == BRACKET_OPEN)
	{
		
	}
	else if (node->type == PIPE)
	{
		
	}
	else if (node->type == AND)
	{

	}
	else if (node->type == OR)
	{
		
	}
}