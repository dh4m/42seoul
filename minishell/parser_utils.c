/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:46:51 by dham              #+#    #+#             */
/*   Updated: 2022/11/08 01:10:29 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

t_astnode	*init_astnode(void)
{
	t_astnode	*ret_val;

	ret_val = malloc(sizeof(t_astnode));
	ret_val->type = -1;
	ret_val->breket = 0;
	ret_val->redi_i = NULL;
	ret_val->redi_o = NULL;
	ret_val->cmd = NULL;
	ret_val->left = NULL;
	ret_val->right = NULL;
	return (ret_val);
}

int avail_node(t_cmdnode *node)
{
	
}