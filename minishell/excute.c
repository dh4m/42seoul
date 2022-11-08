/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:16:27 by dham              #+#    #+#             */
/*   Updated: 2022/11/08 17:42:23 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static void	print_list(t_cmdlist *cmdlist);

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
	/*
	if (make_ast(&cmdlist, &ast))
		; //syntax error
	exc_ast(&ast);
	*/
	print_list(&cmdlist);
	clear_list(&cmdlist);
	clear_ast(&ast.root);
	return (0);
}

int	excute_cmd(char	*cmd)
{
	return (0);
}






/////////////////
static void	print_list(t_cmdlist *cmdlist)
{
	t_cmdnode	*cur_node;

	printf("\n######## token check #############\n");
	cur_node = cmdlist->head;
	while (cur_node)
	{
		if (cur_node->type == PIPE)
			printf("type : PIPE\n");
		else if (cur_node->type == AND)
			printf("type : AND\n");
		else if (cur_node->type == OR)
			printf("type : OR\n");
		else if (cur_node->type == BRACKET_OPEN)
			printf("type : BRACKET_OPEN\n");
		else if (cur_node->type == BRACKET_CLOSE)
			printf("type : BRACKET_CLOSE\n");
		else if (cur_node->type == RE_IN)
			printf("type : RE_IN\n");
		else if (cur_node->type == RE_APPEND)
			printf("type : RE_APPEND\n");
		else if (cur_node->type == RE_OUT)
			printf("type : RE_OUT\n");
		else if (cur_node->type == RE_HEREDOC)
			printf("type : RE_HEREDOC\n");
		else if (cur_node->type == CMD)
			printf("type : CMD\n");
		printf("cmd : %s\n", cur_node->cmd);
		printf("#####################################\n\n");
		cur_node = cur_node->next;
	}
}