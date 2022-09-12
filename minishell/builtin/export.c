/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:55:18 by dham              #+#    #+#             */
/*   Updated: 2022/09/12 21:10:20 by dham             ###   ########.fr       */
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

int	ft_export(char *env_str)
{
	if (!env_str)
	{
		export_env_list();
		return (0);
	}
	else if (ft_strchr(env_str, '=') == NULL)
	{
		add_only_key_env(env_str);
	}
	else
	{
		add_env(env_str);
	}
	return (0);
}