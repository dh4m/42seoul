/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:36:26 by dham              #+#    #+#             */
/*   Updated: 2022/11/04 13:44:27 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

void	init_list_ast(t_cmdlist *cmdlist, t_ast *ast)
{
	cmdlist->head = NULL;
	cmdlist->current = NULL;
	cmdlist->last = NULL;
	cmdlist->node_num = 0;
	ast->root = NULL;
}

int	make_cmdlist(t_cmdlist *cmdlist, t_strbuff *buff)
{
	t_cmdnode *cur_node;

	cur_node = get_token(buff);
	while (cur_node != NULL)
	{
		add_cmdnode(cmdlist, cur_node);
		cur_node = get_token(buff);
	}
	return (0);
}

void	add_cmdnode(t_cmdlist *cmdlist, t_cmdnode *node)
{
	if (cmdlist->node_num == 0)
	{
		node->prev = NULL;
		node->next = NULL;
		cmdlist->head = node;
		cmdlist->last = node;
		cmdlist->current = node;
		cmdlist->node_num++;
		return ;
	}
	node->prev = cmdlist->last;
	node->next = NULL;
	cmdlist->last->next = node;
	cmdlist->last = cmdlist->last->next;
	cmdlist->node_num++;
	return ;
}

void	clear_list(t_cmdlist *cmdlist)
{
	t_cmdnode	*cur_node;
	t_cmdnode	*next_node;

	cur_node = cmdlist->head;
	while (cur_node)
	{
		next_node = cur_node->next;
		if (cur_node->cmd)
			free(cur_node->cmd);
		free(cur_node);
		cur_node = next_node;
	}
}
