/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:54:16 by dham              #+#    #+#             */
/*   Updated: 2022/09/13 14:55:09 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_builtin.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	ft_cd(char *path)
{
	int		ret;
	t_env	*pwd_env;
	t_env	*oldpwd_env;

	pwd_env = search_env("PWD");
	oldpwd_env = search_env("OLDPWD");
	if (oldpwd_env)
	{
		free(oldpwd_env->value);
		oldpwd_env->value = getcwd(NULL, PATH_MAX);
	}
	ret = chdir(path);
	if (ret != 0)
		;//error
	if (pwd_env)
	{
		free(pwd_env->value);
		pwd_env->value = getcwd(NULL, PATH_MAX);
	}
	return (0);
}