/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bracket_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:45:22 by dham              #+#    #+#             */
/*   Updated: 2023/01/20 16:22:01 by dham             ###   ########.fr       */
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
		return (0);
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
		return (node_syntax_error(0, NULL, cmdlist->current));
	cmdlist->current = cmdlist->current->next;
	return (1);
}

t_astnode	*make_bracket_pipeline(t_cmdlist *cmdlist)
{
	t_astnode	*ret_node;
	t_astnode	*left;

	left = make_bracket_node(cmdlist);
	if (!left)
		return (NULL);
	if (!cmdlist->current \
		|| cmdlist->current->type == AND || cmdlist->current->type == OR \
		|| cmdlist->current->type == BRACKET_CLOSE)
		return (left);
	ret_node = make_oper_node(cmdlist);
	if (!ret_node)
		return ((void *)(long)node_syntax_error(0, left, cmdlist->current));
	ret_node->left = left;
	ret_node->right = make_bracket_pipeline(cmdlist);
	if (!ret_node->right)
	{
		clear_ast(ret_node);
		return (NULL);
	}
	return (ret_node);
}

int	check_error_bracket(t_cmdlist *cmdlist)
{
	if (!cmdlist->current)
		return (node_syntax_error(0, NULL, cmdlist->current));
	if (!avail_node(cmdlist->current) || \
		cmdlist->current->type == BRACKET_CLOSE)
		return (node_syntax_error(0, NULL, cmdlist->current));
	return (1);
}

t_astnode	*make_bracket_node(t_cmdlist *cmdlist)
{
	t_astnode	*ret_node;

	ret_node = NULL;
	if (cmdlist->current && cmdlist->current->type == BRACKET_OPEN)
		return (bracket_tree(cmdlist));
	if (!check_error_bracket(cmdlist))
		return (NULL);
	ret_node = init_astnode();
	while (cmdlist->current && avail_node(cmdlist->current) \
			&& cmdlist->current->type != BRACKET_CLOSE)
	{
		if (cmdlist->current->type == BRACKET_OPEN)
			return ((void *)(long)node_syntax_error(0, ret_node, \
													cmdlist->current));
		else if (is_redirection(cmdlist->current->type))
		{
			if (!redir_proc(cmdlist, ret_node))
				return ((void *)(long)node_free_return(0, ret_node));
		}
		else
			cmd_proc(cmdlist, ret_node);
		cmdlist->current = cmdlist->current->next;
	}
	return (ret_node);
}
