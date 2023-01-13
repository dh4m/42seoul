/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strctl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:07:03 by dham              #+#    #+#             */
/*   Updated: 2023/01/13 22:33:15 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include "builtin/ft_builtin.h"
#include "signal/ft_signal.h"
#include "minishell.h"

size_t	list_strlen(t_strlist *list)
{
	t_strnode	*node;
	size_t		ret_val;

	node = list->prenode.next;
	ret_val = 0;
	while (node)
	{
		if (node->content.str)
			ret_val += ft_strlen(node->content.str);
		node = node->next;
	}
	return (ret_val);
}

char	*list_to_str(t_strlist *list)
{
	const size_t	len = list_strlen(list);
	int				cnt;
	char			*ret_val;
	t_strnode		*node;

	cnt = 0;
	node = list->prenode.next;
	while (node)
	{
		cnt++;
		node = node->next;
	}
	if (cnt == 0)
		return (ft_calloc(1, sizeof(char)));
	ret_val = ft_calloc(len + cnt, sizeof(char));
	node = list->prenode.next;
	while (node)
	{
		ft_strlcat(ret_val, node->content.str, len + cnt);
		ft_strlcat(ret_val, " ", len + cnt);
		node = node->next;
	}
	return (ret_val);
}

char	*table_to_str(char **table)
{
	size_t	len;
	int		i;
	int		cnt;
	char	*ret_str;

	len = 0;
	i = -1;
	while (table[++i])
		len += ft_strlen(table[i]);
	ret_str = ft_calloc(len + i + 1, sizeof(char));
	cnt = i;
	i = -1;
	while (table[++i])
	{
		ft_strlcat(ret_str, table[i], len + cnt + 1);
		ft_strlcat(ret_str, " ", len + cnt + 1);
	}
	return (ret_str);
}

char	*strreplace(char *str, size_t start, size_t end, char *rep)
{
	char	*ret_str;
	char	*front;
	char	*back;
	int		len;

	front = ft_substr(str, 0, start);
	back = ft_substr(str, end + 1, ft_strlen(&str[end + 1]));
	len = ft_strlen(str) - (end - start + 1) + ft_strlen(rep);
	ret_str = malloc(len + 1);
	ft_strlcpy(ret_str, front, len + 1);
	ft_strlcat(ret_str, rep, len + 1);
	ft_strlcat(ret_str, back, len + 1);
	free(front);
	free(back);
	free(str);
	return (ret_str);
}

char	**get_argv(t_astnode *node)
{
	char	*temp_str;
	char	**ret_val;

	if (node->type != CMD)
		return (NULL);
	temp_str = list_to_str(&node->cmd);
	temp_str = expansion(temp_str);
	ret_val = shell_split(temp_str, ' ');
	wildcard(ret_val);
	free(temp_str);
	temp_str = table_to_str(ret_val);
	free_path_list(ret_val);
	ret_val = shell_split(temp_str, ' ');
	quote_proc(ret_val);
	remove_escape(ret_val);
	free(temp_str);
	return (ret_val);
}

char	*filename_expansion(char *str)
{
	char	**name_list;
	char	*ret_str;
	char	*temp_str;

	temp_str = ft_strdup(str);
	temp_str = expansion(temp_str);
	name_list = shell_split(temp_str, ' ');
	wildcard(name_list);
	free(temp_str);
	temp_str = table_to_str(name_list);
	free_path_list(name_list);
	name_list = shell_split(temp_str, ' ');
	quote_proc(name_list);
	free(temp_str);
	if (name_list[1])
	{
		free_path_list(name_list);
		return (0);
	}
	ret_str = ft_strdup(name_list[0]);
	free_path_list(name_list);
	return (ret_str);
}
