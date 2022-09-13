/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:55:18 by dham              #+#    #+#             */
/*   Updated: 2022/09/13 21:00:11 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_builtin.h"
#include "libft.h"

int	export_env_list(void)
{
	t_env	*env;

	env = g_info.env;
	while (env)
	{
		printf("declare -x %s=\"%s\"\n", env->name, env->value);
		env = env->next;
	}
	return (0);
}

int	ft_export_value(char *env_str)
{
	char	*name;
	char	*value;
	t_env	*exist_env;

	name = ft_substr(env_str, 0, ft_strchr(env_str, '=') - env_str);
	value = ft_substr(ft_strchr(env_str, '=') + 1, 0, strlen(env_str));
	exist_env = search_env(name);
	if (exist_env)
	{
		free(exist_env->value);
		exist_env->value = value;
	}
	else
		add_env(env_str);
	free(name);
	return (0);
}

int	ft_export_name(char *env_str)
{
	if (!search_env(env_str))
		add_only_key_env(env_str);
	return (0);
}

int	ft_export(char *env_str)
{
	if (!env_str)
	{
		export_env_list();
		return (0);
	}
	else if (ft_strchr(env_str, '=') == NULL)
		ft_export_name(env_str);
	else
		ft_export_value(env_str);
}
