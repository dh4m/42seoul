/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:54:16 by dham              #+#    #+#             */
/*   Updated: 2022/12/26 19:23:47 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_builtin.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void	getcwd_error(void)
{
	ft_putstr_fd("cd: error retrieving current directory: ", 2);
	ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
	ft_putstr_fd("No such file or directory\n", 2);
}

char	*get_oldpwd(void)
{
	t_env	*tmp;
	char	*ret_str;

	ret_str = getcwd(NULL, PATH_MAX);
	if (!ret_str)
	{
		tmp = search_env("PWD");
		if (tmp)
			ret_str = ft_strdup(tmp->value);
	}
	return (ret_str);
}

char	*get_pwd(char *path)
{
	t_env	*tmp;
	char	*tmp_str;
	char	*ret_str;

	ret_str = getcwd(NULL, PATH_MAX);
	if (!ret_str)
	{
		getcwd_error();
		tmp = search_env("PWD");
		if (tmp)
		{
			tmp_str = ft_strjoin(tmp->value, "/");
			ret_str = ft_strjoin(tmp_str, path);
			free(tmp_str);
		}
	}
	return (ret_str);
}

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

	oldpwd = get_oldpwd();
	ret = chdir(path);
	if (ret != 0)
	{
		cd_error(path);
		free(oldpwd);
		g_info.ret_val = 1;
		return (0);
	}
	pwd = get_pwd(path);
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
	else if (search_env("HOME"))
		ft_cd(search_env("HOME")->value);
	else
		ft_putstr_fd("minishell: cd: ONLY a relative or absolute path\n", 2);
	return (0);
}