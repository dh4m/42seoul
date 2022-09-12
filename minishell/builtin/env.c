/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:55:07 by dham              #+#    #+#             */
/*   Updated: 2022/09/12 20:49:59 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_builtin.h"

int	ft_env(void)
{
	t_env	*env;

	env = g_info.env;
	while (env)
	{
		printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
	return (0);
}