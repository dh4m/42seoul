/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:36:26 by dham              #+#    #+#             */
/*   Updated: 2022/09/29 22:24:42 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int	proc_cmd(char *cmd)
{
	t_cmdlist	cmdlist;
	t_ast		ast;
	t_strbuff	buff;

	buff.str = cmd;
	buff.len = ft_strlen(cmd);
	buff.now_read = 0;
	init_list_ast(&cmdlist, &ast);
	make_cmdlist(&cmdlist, &buff);
	make_ast(&cmdlist, &ast);
	exc_ast(&ast);
	clear_list(&cmdlist);
	clear_ast(&ast);
	return (0);
}

void	init_list_ast(t_cmdlist *cmdlist, t_ast *ast)
{
	cmdlist->head = NULL;
	cmdlist->current = NULL;
	cmdlist->node_num = 0;
	ast->root = NULL;
}

void	make_cmdlist(t_cmdlist *cmdlist, t_strbuff *buff)
{
	if (bracket_check())
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

int	bracket_check(char *str)
{
	int	i;

	while (ft_isblank(str[i]))
		i++;
	if (ft_isoper(str[i]) == BRACKET)
		return (1);
	return (0);
}
