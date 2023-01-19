/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:55:22 by dham              #+#    #+#             */
/*   Updated: 2023/01/19 18:20:09 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtin.h"
#include "../minishell.h"
#include "libft.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_pwd(void)
{
	char	*path;
	t_env	*tmp;

	path = getcwd(NULL, PATH_MAX);
	if (!path)
	{
		tmp = search_env("PWD");
		if (tmp)
			path = ft_strdup(tmp->value);
		else
			path = ft_strdup("Invalid path");
	}
	printf("%s\n", path);
	free(path);
	return (0);
}

int	exe_pwd(char **argv)
{
	(void)argv;
	ft_pwd();
	g_info.ret_val = 0;
	return (0);
}
