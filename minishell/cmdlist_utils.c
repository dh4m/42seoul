/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:53:39 by dham              #+#    #+#             */
/*   Updated: 2022/10/03 19:42:22 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

t_cmdnode	*get_token(t_strbuff *buff)
{
	t_cmdnode	*ret_node;
	int			len;

	while (ft_isblank(buff->str[buff->now_read]))
		buff->now_read++;
	if (buff->now_read == buff->len)
		return (NULL);
	ret_node = malloc(sizeof(t_cmdnode));
	ret_node->type = ft_isoper(&buff->str[buff->now_read]);
	if (ret_node->type != CMD)
	{
		ret_node->cmd = NULL;
		if (ret_node->type == AND || ret_node->type == OR ||\
			ret_node->type == RE_APPEND || ret_node->type == RE_HEREDOC)
			buff->now_read += 2;
		else
			buff->now_read++;
		return (ret_node);
	}
	len = cmd_len(&buff->str[buff->now_read]);
	ret_node->cmd = ft_substr(&buff->str[buff->now_read], 0, len);
	buff->now_read += len;
	return (ret_node);
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
		}
		else
			i++;
	}
	return (i);
}
