/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:16:27 by dham              #+#    #+#             */
/*   Updated: 2023/01/19 18:17:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

//static void	print_list(t_cmdlist *cmdlist);

int	proc_cmd(char *cmd)
{
	t_cmdlist	cmdlist;
	t_ast		ast;
	t_strbuff	buff;
	char		*escape;

	escape = insert_escape(cmd, BACKSLASH_E);
	buff.str = escape;
	buff.len = ft_strlen(escape);
	buff.now_read = 0;
	init_list_ast(&cmdlist, &ast);
	if (!(make_cmdlist(&cmdlist, &buff) < 0 || !make_ast(&cmdlist, &ast)))
		exe_ast(ast.root, 1);
	turn_off_show_signal();
	clear_list(&cmdlist);
	clear_ast(ast.root);
	free(escape);
	return (0);
}

/* // for debug

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
*/