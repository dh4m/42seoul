/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:41:10 by dham              #+#    #+#             */
/*   Updated: 2023/01/23 12:28:42 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "minishell.h"
#include "libft.h"

void	info_init(char **envp)
{
	int		i;
	int		tmp;
	t_env	*shlvl;

	i = 0;
	g_info.ret_val = 0;
	while (envp[i])
	{
		add_env(envp[i]);
		i++;
	}
	shlvl = search_env("SHLVL");
	if (shlvl && shlvl->value)
	{
		tmp = ft_atoi(shlvl->value);
		tmp++;
		free(shlvl->value);
		shlvl->value = ft_itoa(tmp);
	}
	add_env("CLICOLOR=1");
}
