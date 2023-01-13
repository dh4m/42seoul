/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_strctl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:29:38 by dham              #+#    #+#             */
/*   Updated: 2023/01/13 17:45:02 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int	cmd_proc(t_cmdlist *cmdlist, t_astnode *node)
{
	add_strnode(cmdlist->current->cmd, 0, CMD, &node->cmd);
	return (1);
}

int	redir_proc(t_cmdlist *cmdlist, t_astnode *node)
{
	if (!cmdlist->current->next || cmdlist->current->next->type != CMD)
		return (node_syntax_error(0, NULL, cmdlist->current->next));
	if (cmdlist->current->type == RE_HEREDOC)
	{
		if (!heredoc_proc(cmdlist->current->next->cmd, &node->redi))
			return (0);
	}
	else 
		add_strnode(cmdlist->current->next->cmd, 0, \
					cmdlist->current->type, &node->redi);
	cmdlist->current = cmdlist->current->next;
	return (1);
}

void	add_strnode(char *str, int heredoc_fd, int type, t_strlist *list)
{
	t_strnode	*last;
	t_strnode	*node;

	node = malloc(sizeof(t_strnode));
	node->type = type;
	node->next = NULL;
	if (str)
		node->content.str = str;
	else
		node->content.fd = heredoc_fd;
	last = &list->prenode;
	while (last->next)
		last = last->next;
	last->next = node;
	list->node_num++;
}
