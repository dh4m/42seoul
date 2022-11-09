/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_strctl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:29:38 by dham              #+#    #+#             */
/*   Updated: 2022/11/09 14:51:19 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int	cmd_proc(t_cmdlist *cmdlist, t_astnode *node)
{
	add_strnode(cmdlist->current->cmd, &node->cmd);
	cmdlist->current = cmdlist->current->next;
	return (1);
}

int	redir_proc(t_cmdlist *cmdlist, t_astnode *node)
{
	if (!cmdlist->current->next || cmdlist->current->next->type != CMD)
		return (0); //error
	if (cmdlist->current->type == RE_HEREDOC)
	{
		; //heredoc proc
	}
	else if (cmdlist->current->type == RE_IN)
	{

	}
	else
	{
		add_strnode(cmdlist->current->next->cmd, &node->cmd);
	}
	return (1);
}

void	add_strnode(char *str, t_strlist *list)
{
	t_strnode	*last;
	t_strnode	*node;

	node = malloc(sizeof(t_strnode));
	node->next = NULL;
	node->str = str;
	last = &list->prenode;
	while (last->next)
		last = last->next;
	last->next = node;
}
