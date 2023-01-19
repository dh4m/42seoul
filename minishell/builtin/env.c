/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:55:07 by dham              #+#    #+#             */
/*   Updated: 2023/01/19 18:19:53 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_builtin.h"
#include <stdio.h>

int	ft_env(void)
{
	t_env	*env;

	env = g_info.env;
	while (env)
	{
		if (env->value)
			printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
	return (0);
}

int	exe_env(char **argv)
{
	(void)argv;
	ft_env();
	g_info.ret_val = 0;
	return (0);
}
