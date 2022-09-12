/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:14:47 by dham              #+#    #+#             */
/*   Updated: 2022/09/12 20:08:08 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "libft.h"

void	add_env(char *env_str)
{
	char	*value;
	int		name_len;
	int		value_len;
	t_env	*add_node;

	add_node = malloc(sizeof(t_env));
	value = ft_strchr(env_str, '=') + 1;
	name_len = value - env_str - 1;
	value_len = ft_strlen(value);
	add_node->next = NULL;
	add_node->name = ft_substr(env_str, 0, name_len);
	add_node->value = ft_substr(value, 0, value_len);
	if (g_info.env_last == NULL)
	{
		g_info.env = add_node;
		g_info.env_last = g_info.env;
	}
	else
	{
		g_info.env_last->next = add_node;
		g_info.env_last = g_info.env_last->next;
	}
}

void	add_only_key_env(char *env_name)
{
	int		name_len;
	t_env	*add_node;

	add_node = malloc(sizeof(t_env));
	name_len = ft_strlen(env_name);
	add_node->next = NULL;
	add_node->name = ft_substr(env_name, 0, name_len);
	add_node->value = NULL;
	if (g_info.env_last == NULL)
	{
		g_info.env = add_node;
		g_info.env_last = g_info.env;
	}
	else
	{
		g_info.env_last->next = add_node;
		g_info.env_last = g_info.env_last->next;
	}
}

t_env	*search_env(char *name)
{
	t_env	*ret_node;
	
	ret_node = g_info.env;
	while (ret_node)
	{
		if (ft_strncmp(name, ret_node->name, ft_strlen(name)) == 0)
			break;
		ret_node = ret_node->next;
	}
	return (ret_node);
}

void	del_env(char *name)
{
	t_env	*pre_node;
	t_env	*del_node;
	
	del_node = g_info.env;
	if (del_node && ft_strncmp(name, del_node->name, ft_strlen(name)) == 0)
	{
		g_info.env = g_info.env->next;
		free(del_node->name);
		free(del_node->value);
		free(del_node);
		return ;
	}
	while (del_node && del_node->next)
	{
		pre_node = del_node;
		del_node = del_node->next;
		if (ft_strncmp(name, del_node->name, ft_strlen(name)) == 0)
		{
			pre_node->next = pre_node->next->next;
			free(del_node->name);
			free(del_node->value);
			free(del_node);
			break;
		}
	}
}