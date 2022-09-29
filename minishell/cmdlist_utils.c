/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdlist_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:53:39 by dham              #+#    #+#             */
/*   Updated: 2022/09/29 22:24:38 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

t_cmdnode	*get_cmd(t_strbuff *buff)
{
	t_cmdnode	*ret_node;
	int			len;

	ret_node = malloc(sizeof(t_cmdnode));
	ret_node->type = CMD;
	while (ft_isblank(buff->str[buff->now_read]))
		buff->now_read++;
	len = cmd_len(&(buff->str[buff->now_read]));
	if (len == 0)
		; // syntax error
	ret_node->cmd = ft_substr(&buff->str[buff->now_read], 0, len);
	if (bracket_error(ret_node->cmd))
		; // syntax error
	ret_node->prev = NULL;
	ret_node->next = NULL;
	return (ret_node);
}

int	cmd_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] && ft_isoper(str[len]) == -1)
	{
		if (ft_isquotes(str[len]) && ++len)
		{
			while (str[len] && !ft_isquotes(str[len]))
				len++;
			len++;////////////////quotes
		}
		else
			len ++;
	}
	return (len);
}

int	bracket_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ')')
			return (1);
		i++;
	}
	return (0);
}