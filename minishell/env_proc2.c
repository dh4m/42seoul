/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_proc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:06:48 by dham              #+#    #+#             */
/*   Updated: 2023/01/11 15:32:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "libft.h"

int	valid_env_name(char *name)
{
	int	i;

	i = 0;
	if (!ft_isalpha(name[i]) && name[i] != '_')
		return (0);
	while (name[++i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
	}
	return (1);
}

int	num_of_env(void)
{
	int		ret_num;
	t_env	*env;

	ret_num = 0;
	env = g_info.env;
	while(env)
	{
		if (env->value)
			ret_num++;
		env = env->next;
	}
	return (ret_num);
}

char	**env_list_make(void)
{
	int			i;
	t_env		*env;
	char		**ret_list;
	int			len_env_str;

	ret_list = malloc(sizeof(char *) * num_of_env() + 1);
	env = g_info.env;
	i = 0;
	while (env)
	{
		if (env->value)
		{
			len_env_str = ft_strlen(env->name) + ft_strlen(env->value) + 2;
			ret_list[i] = malloc(len_env_str);
			ft_strlcpy(ret_list[i], env->name, len_env_str);
			ft_strlcat(ret_list[i], "=", len_env_str);
			ft_strlcat(ret_list[i], env->value, len_env_str);
			i++;
		}
		env = env->next;
	}
	ret_list[i] = NULL;
	return (ret_list);
}
