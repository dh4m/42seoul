/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:54:37 by dham              #+#    #+#             */
/*   Updated: 2022/11/15 21:59:17 by dham             ###   ########.fr       */
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
		return (0); //error
	ast->root = pipe_set;
	while (cmdlist->current)
	{
		logic_oper = make_node(cmdlist);
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
	t_astnode *ret_node;
	t_astnode *left;

	left = make_node(cmdlist);
	if (!left)
		return (NULL); //error
	if (!cmdlist->current || \
		cmdlist->current->type == AND || cmdlist->current->type == OR)
		return (left);
	ret_node = make_node(cmdlist);
	ret_node->left = left;
	ret_node->right = make_pipeline(cmdlist);
	if (!ret_node->right)
	{
		clear_ast(ret_node);
		return (NULL); //error
	}
	return (ret_node);
}

t_astnode	*make_node(t_cmdlist *cmdlist)
{
	t_astnode	*ret_node;

	ret_node = init_astnode();
	if (!avail_node(cmdlist->current))
		; //error
	if (cmdlist->current->type == BRACKET_OPEN)
	{
		;//bracket_proc
	}
	while (cmdlist->current && avail_node(cmdlist->current))
	{
		if (cmdlist->current->type == BRACKET_OPEN || \
			cmdlist->current->type == BRACKET_CLOSE)
			; //error
		else if (is_redirection(cmdlist->current->type))
		{
			if (!redir_proc(cmdlist, ret_node))
				; //error
		}
		else
		{
			cmd_proc(cmdlist, ret_node);
		}
		cmdlist->current = cmdlist->current->next;
	}
	return (ret_node);
}



void	clear_ast(t_astnode *root)
{
	if (root == NULL)
		return ;
	clear_ast(root->left);
	clear_ast(root->right);
	clear_strlist(&root->redi_i);
	clear_strlist(&root->redi_o);
	clear_strlist(&root->cmd);
	free(root);
}
