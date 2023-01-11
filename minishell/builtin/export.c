/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:55:18 by dham              #+#    #+#             */
/*   Updated: 2023/01/11 16:25:34 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_builtin.h"
#include "libft.h"
#include <stdio.h>

int	export_env_list(void)
{
	t_env	*env;

	env = g_info.env;
	while (env)
	{
		if (env->value)
			printf("declare -x %s=\"%s\"\n", env->name, env->value);
		else
			printf("declare -x %s\n", env->name);
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
	value = ft_substr(ft_strchr(env_str, '=') + 1, 0, ft_strlen(env_str));
	exist_env = search_env(name);
	if (exist_env)
	{
		free(exist_env->value);
		exist_env->value = value;
	}
	else
	{
		add_env(env_str);
		free(value);
	}
	free(name);
	return (0);
}

int	ft_export_name(char *env_str)
{
	if (!search_env(env_str))
	{
		add_only_key_env(env_str);
	}
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
	return (0);
}

int	exe_export(char **argv)
{
	int	i;
	int	err;

	if (!argv[1])
		ft_export(NULL);
	i = 0;
	err = 0;
	while (argv[++i])
	{
		if (!valid_name(argv[i]))
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			err = 1;
			continue ;
		}
		ft_export(argv[i]);
	}
	if (err)
		g_info.ret_val = 1;
	else
		g_info.ret_val = 0;
	return (0);
}
