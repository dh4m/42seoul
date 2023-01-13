/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:53:39 by dham              #+#    #+#             */
/*   Updated: 2023/01/13 17:49:58 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int	get_token(t_strbuff *buff, t_cmdnode **cur_node)
{
	int			len;

	while (ft_isblank(buff->str[buff->now_read]))
		buff->now_read++;
	if (buff->now_read == buff->len)
	{
		*cur_node = NULL;
		return (0);
	}
	*cur_node = malloc(sizeof(t_cmdnode));
	(*cur_node)->type = ft_isoper(&buff->str[buff->now_read]);
	if ((*cur_node)->type != CMD)
	{
		(*cur_node)->cmd = NULL;
		if ((*cur_node)->type == AND || (*cur_node)->type == OR || \
			(*cur_node)->type == RE_APPEND || (*cur_node)->type == RE_HEREDOC)
			buff->now_read += 2;
		else
			buff->now_read++;
		return (0);
	}
	len = cmd_len(&buff->str[buff->now_read]);
	if (len < 0)
	{
		free(*cur_node);
		node_syntax_error(0, NULL, NULL);
		return (-1);
	}
	(*cur_node)->cmd = ft_substr(&buff->str[buff->now_read], 0, len);
	buff->now_read += len;
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
