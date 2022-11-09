/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:46:51 by dham              #+#    #+#             */
/*   Updated: 2022/11/09 10:29:07 by dham             ###   ########.fr       */
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
	ret_val->redi_i.prenode.str = NULL;
	ret_val->redi_i.prenode.next = NULL;
	ret_val->redi_i.node_num = 0;
	ret_val->redi_o.prenode.str = NULL;
	ret_val->redi_o.prenode.next = NULL;
	ret_val->redi_o.node_num = 0;
	ret_val->cmd.prenode.str = NULL;
	ret_val->cmd.prenode.next = NULL;
	ret_val->cmd.node_num = 0;
	ret_val->left = NULL;
	ret_val->right = NULL;
	return (ret_val);
}

void	clear_strlist(t_strlist *list)
{
	t_strnode	*cur_node;
	t_strnode	*next_node;

	if (list->node_num == 0)
		return ;
	cur_node = list->prenode.next;
	while (cur_node)
	{
		next_node = cur_node->next;
		free(cur_node);
		cur_node = next_node;
	}
}

int avail_node(t_cmdnode *node)
{
	return (node->type != PIPE && node->type != AND && node->type != OR);
}

int	is_redirection(int type)
{
	return (type == RE_APPEND || type == RE_IN || \
			type == RE_OUT || type == RE_HEREDOC);
}
