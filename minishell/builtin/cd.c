/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:54:16 by dham              #+#    #+#             */
/*   Updated: 2022/12/23 15:07:03 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_builtin.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void	cd_error(char *name)
{
	char	*err_str;

	err_str = ft_strjoin("minishell: ", name);
	perror(err_str);
	free(err_str);
}

int	ft_cd(char *path)
{
	int		ret;
	char	*pwd;
	char	*oldpwd;

	oldpwd = getcwd(NULL, PATH_MAX);
	ret = chdir(path);
	if (ret != 0)
	{
		cd_error(path);
		free(oldpwd);
		g_info.ret_val = 1;
		return (0);
	}
	pwd = getcwd(NULL, PATH_MAX);
	cd_env_set(pwd, oldpwd);
	g_info.ret_val = 0;
	return (0);
}

void	cd_env_set(char *pwd, char *oldpwd)
{
	t_env	*pwd_env;
	t_env	*oldpwd_env;

	pwd_env = search_env("PWD");
	oldpwd_env = search_env("OLDPWD");
	if (oldpwd_env)
	{
		if (oldpwd_env->value)
			free(oldpwd_env->value);
		oldpwd_env->value = oldpwd;
	}
	else
		free(oldpwd);
	if (pwd_env)
	{
		if (pwd_env->value)
			free(pwd_env->value);
		pwd_env->value = pwd;
	}
	else
		free(pwd);
}

int exe_cd(char **argv)
{
	if (argv[1])
		ft_cd(argv[1]);
	else
		ft_cd(search_env("HOME")->value);
	return (0);
}