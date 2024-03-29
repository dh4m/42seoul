/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:54:37 by dham              #+#    #+#             */
/*   Updated: 2023/01/20 16:22:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int	make_ast(t_cmdlist *cmdlist, t_ast *ast)
{
	t_astnode	*pipe_set;
	t_astnode	*logic_oper;

	pipe_set = make_pipeline(cmdlist);
	if (!pipe_set)
		return (0);
	ast->root = pipe_set;
	while (cmdlist->current)
	{
		logic_oper = make_oper_node(cmdlist);
		logic_oper->left = ast->root;
		ast->root = logic_oper;
		logic_oper->right = make_pipeline(cmdlist);
		if (!logic_oper->right)
			return (0);
	}
	return (1);
}

t_astnode	*make_pipeline(t_cmdlist *cmdlist)
{
	t_astnode	*ret_node;
	t_astnode	*left;

	left = make_node(cmdlist);
	if (!left)
		return (NULL);
	if (!cmdlist->current || \
		cmdlist->current->type == AND || cmdlist->current->type == OR)
		return (left);
	ret_node = make_oper_node(cmdlist);
	if (!ret_node)
		return ((void *)(long)node_syntax_error(0, left, cmdlist->current));
	ret_node->left = left;
	ret_node->right = make_pipeline(cmdlist);
	if (!ret_node->right)
	{
		clear_ast(ret_node);
		return (NULL);
	}
	return (ret_node);
}

t_astnode	*make_node(t_cmdlist *cmdlist)
{
	t_astnode	*ret_node;

	ret_node = NULL;
	if (cmdlist->current && cmdlist->current->type == BRACKET_OPEN)
		return (bracket_tree(cmdlist));
	if (!check_error(cmdlist))
		return (NULL);
	ret_node = init_astnode();
	while (cmdlist->current && avail_node(cmdlist->current))
	{
		if (cmdlist->current->type == BRACKET_OPEN || \
			cmdlist->current->type == BRACKET_CLOSE)
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

t_astnode	*make_oper_node(t_cmdlist *cmdlist)
{
	t_astnode	*ret_node;

	if (cmdlist->current->type != AND && cmdlist->current->type != OR \
		&& cmdlist->current->type != PIPE)
		return (0);
	ret_node = init_astnode();
	ret_node->type = cmdlist->current->type;
	cmdlist->current = cmdlist->current->next;
	return (ret_node);
}

void	clear_ast(t_astnode *root)
{
	if (root == NULL)
		return ;
	clear_ast(root->left);
	clear_ast(root->right);
	clear_strlist(&(root->redi));
	clear_strlist(&(root->cmd));
	free(root);
}
