/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_strctl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:29:38 by dham              #+#    #+#             */
/*   Updated: 2022/12/26 18:40:10 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int	cmd_proc(t_cmdlist *cmdlist, t_astnode *node)
{
	add_strnode(cmdlist->current->cmd, CMD, &node->cmd);
	return (1);
}

int	redir_proc(t_cmdlist *cmdlist, t_astnode *node)
{
	if (!cmdlist->current->next || cmdlist->current->next->type != CMD)
		return (node_syntax_error(0, NULL)); //error
	if (cmdlist->current->type == RE_HEREDOC) // heredoc
	{
		if (!heredoc_proc(cmdlist->current->next->cmd, &node->redi))////////
			return (0); //error
	}
	else if (cmdlist->current->type == RE_IN) // redirection input
		add_strnode(cmdlist->current->next->cmd, RE_IN, &node->redi);
	else // redirection output
		add_strnode(cmdlist->current->next->cmd, cmdlist->current->type, &node->redi);
	cmdlist->current = cmdlist->current->next;
	return (1);
}

void	add_strnode(char *str, int type, t_strlist *list)
{
	t_strnode	*last;
	t_strnode	*node;

	node = malloc(sizeof(t_strnode));
	node->type = type;
	node->next = NULL;
	node->str = str;
	last = &list->prenode;
	while (last->next)
		last = last->next;
	last->next = node;
	list->node_num++;
}
