/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_proc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:06:48 by dham              #+#    #+#             */
/*   Updated: 2022/09/13 20:53:39 by dham             ###   ########.fr       */
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
		ret_num++;
		env = env->next;
	}
	return (ret_num);
}

char	**env_list_make(void)
{
	int		i;
	int		env_num;
	t_env	*env;
	char	**ret_list;

	env_num = 0;
	env = g_info.env;
	while (env && ++env_num)
		env = env->next;
	ret_list = malloc(sizeof(char *) * env_num);
	env = g_info.env;
	i = 0;
	while (env)
	{
		ret_list[i] = malloc(ft_strlen(env->name) + ft_strlen(env->value) + 2);
		ft_strlcpy(ret_list[i], env->name, ft_strlen(env->name) + 1);
		
	}
}
