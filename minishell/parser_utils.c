/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:46:51 by dham              #+#    #+#             */
/*   Updated: 2023/01/13 16:34:02 by dham             ###   ########.fr       */
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
	ret_val->type = CMD;
	ret_val->redi.prenode.content.str = NULL;
	ret_val->redi.prenode.next = NULL;
	ret_val->redi.node_num = 0;
	ret_val->cmd.prenode.content.str = NULL;
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

	if (!list)
		return ;
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
	return (node && node->type != PIPE \
			&& node->type != AND && node->type != OR);
}

int	is_redirection(int type)
{
	return (type == RE_APPEND || type == RE_IN || \
			type == RE_OUT || type == RE_HEREDOC);
}
