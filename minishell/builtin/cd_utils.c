/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:58:39 by dham              #+#    #+#             */
/*   Updated: 2023/01/18 20:01:44 by dham             ###   ########.fr       */
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
	perror("getcwd: cannot access parent directories");
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
		else
			ret_str = ft_calloc(1, sizeof(char));
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
		else
			ret_str = ft_calloc(1, sizeof(char));
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
