/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:53:39 by dham              #+#    #+#             */
/*   Updated: 2023/01/19 17:46:31 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

t_cmdnode	*make_cmdnode(t_strbuff *buff)
{
	t_cmdnode	*cur_node;
	int			len;

	cur_node = ft_calloc(1, sizeof(t_cmdnode));
	cur_node->type = ft_isoper(&buff->str[buff->now_read]);
	if (cur_node->type != CMD)
	{
		buff->now_read += ft_oper_len(cur_node->type);
		return (cur_node);
	}
	len = cmd_len(&buff->str[buff->now_read]);
	if (len < 0)
	{
		free(cur_node);
		node_syntax_error(0, NULL, NULL);
		return (NULL);
	}
	cur_node->cmd = ft_substr(&buff->str[buff->now_read], 0, len);
	buff->now_read += len;
	return (cur_node);
}

int	get_token(t_strbuff *buff, t_cmdnode **cur_node)
{
	while (ft_isblank(buff->str[buff->now_read]))
		buff->now_read++;
	if (buff->now_read == buff->len)
	{
		*cur_node = NULL;
		return (0);
	}
	*cur_node = make_cmdnode(buff);
	if (*cur_node == NULL)
		return (-1);
	return (0);
}

int	cmd_len(char *cmd)
{
	int	i;
	int	quotes;

	i = 0;
	while (cmd[i] && !ft_ismeta(&cmd[i]))
	{
		quotes = ft_isquotes(cmd[i]);
		if (quotes != CMD)
		{
			i++;
			while (cmd[i] && ft_isquotes(cmd[i]) != quotes)
				i++;
			if (ft_isquotes(cmd[i]) == quotes)
				i++;
			else
				return (-1);
		}
		else
			i++;
	}
	return (i);
}
