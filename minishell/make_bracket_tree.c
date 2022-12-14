/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bracket_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:45:22 by dham              #+#    #+#             */
/*   Updated: 2022/12/26 16:49:53 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int	make_bracket_ast(t_cmdlist *cmdlist, t_ast *ast)
{
	t_astnode	*pipe_set;
	t_astnode	*logic_oper;

	pipe_set = make_bracket_pipeline(cmdlist);
	if (!pipe_set)
		return (0); //error
	ast->root = pipe_set;
	while (cmdlist->current && cmdlist->current->type != BRACKET_CLOSE)
	{
		logic_oper = make_oper_node(cmdlist);
		logic_oper->left = ast->root;
		ast->root = logic_oper;
		logic_oper->right = make_bracket_pipeline(cmdlist);
		if (!logic_oper->right)
			return (0);
	}
	if (!cmdlist->current)
		return (node_syntax_error(0, NULL)); //error
	cmdlist->current = cmdlist->current->next;
	return (1);
}

t_astnode	*make_bracket_pipeline(t_cmdlist *cmdlist)
{
	t_astnode *ret_node;
	t_astnode *left;

	left = make_bracket_node(cmdlist);
	if (!left)
		return (NULL); //error
	if (!cmdlist->current \
		|| cmdlist->current->type == AND || cmdlist->current->type == OR \
		|| cmdlist->current->type == BRACKET_CLOSE)
		return (left);
	ret_node = make_oper_node(cmdlist);
	ret_node->left = left;
	ret_node->right = make_bracket_pipeline(cmdlist);
	if (!ret_node->right)
	{
		clear_ast(ret_node);
		return (NULL); //error
	}
	return (ret_node);
}

t_astnode	*make_bracket_node(t_cmdlist *cmdlist)
{
	t_astnode	*ret_node;

	if (cmdlist->current->type == BRACKET_OPEN)
		return (bracket_tree(cmdlist)); //bracket_tree_return///
	if (!avail_node(cmdlist->current) || cmdlist->current->type == BRACKET_CLOSE)
		return ((void *)(long)node_syntax_error(0, NULL)); //error
	ret_node = init_astnode();
	while (cmdlist->current && avail_node(cmdlist->current) \
			&& cmdlist->current->type != BRACKET_CLOSE)
	{
		if (cmdlist->current->type == BRACKET_OPEN)
			return ((void *)(long)node_syntax_error(0, ret_node)); //error
		else if (is_redirection(cmdlist->current->type))
		{
			if (!redir_proc(cmdlist, ret_node))
				return ((void *)(long)node_return(0, ret_node)); //error
		}
		else
			cmd_proc(cmdlist, ret_node);
		cmdlist->current = cmdlist->current->next;
	}
	return (ret_node);
}
