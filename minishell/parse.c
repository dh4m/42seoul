/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:36:26 by dham              #+#    #+#             */
/*   Updated: 2022/09/27 22:02:59 by dham             ###   ########.fr       */
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
	
}

void	add_cmdnode()
