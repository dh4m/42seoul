/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:36:26 by dham              #+#    #+#             */
/*   Updated: 2022/10/03 20:41:56 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

//static void	print_list(t_cmdlist *cmdlist);

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
	//if (make_cmdlist(&cmdlist, &buff)) // heredoc을 여기서???????
	//	; // syntax error
	/*preproc_cmdlist(&cmdlist); //redirection 들 처리 and 확장 등
	make_ast(&cmdlist, &ast);
	exc_ast(&ast);
	clear_list(&cmdlist);
	clear_ast(&ast);*/
	print_list(&cmdlist);
	return (0);
}

void	init_list_ast(t_cmdlist *cmdlist, t_ast *ast)
{
	cmdlist->head = NULL;
	cmdlist->current = NULL;
	cmdlist->last = NULL;
	cmdlist->node_num = 0;
	ast->root = NULL;
}

int	make_cmdlist(t_cmdlist *cmdlist, t_strbuff *buff)
{
	t_cmdnode *cur_node;

	cur_node = get_token(buff);
	while (cur_node != NULL)
	{
		add_cmdnode(cmdlist, cur_node);
		cur_node = get_token(buff);
	}
	return (0);
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

/*////////
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
}*/