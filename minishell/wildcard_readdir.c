/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_readdir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:52:31 by dham              #+#    #+#             */
/*   Updated: 2023/01/18 19:51:46 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include "builtin/ft_builtin.h"
#include "signal/ft_signal.h"
#include "minishell.h"
#include <dirent.h>
#include <sys/stat.h>

int	cur_dir_list_len(void)
{
	DIR				*dp;
	struct dirent	*entry;
	int				ret_val;

	ret_val = 0;
	dp = opendir(".");
	entry = readdir(dp);
	while (entry)
	{
		ret_val++;
		entry = readdir(dp);
	}
	closedir(dp);
	return (ret_val);
}

char	**cur_dir_list(void)
{
	DIR				*dp;
	struct dirent	*entry;
	int				i;
	char			**ret_list;

	ret_list = malloc(sizeof(char *) * (cur_dir_list_len() + 1));
	i = 0;
	dp = opendir(".");
	entry = readdir(dp);
	while (entry)
	{
		ret_list[i] = malloc(ft_strlen(entry->d_name) + 1);
		ft_strlcpy(ret_list[i], entry->d_name, \
					ft_strlen(entry->d_name) + 1);
		i++;
		entry = readdir(dp);
	}
	ret_list[i] = NULL;
	closedir(dp);
	return (ret_list);
}

int	cur_dir_onlydir_len(void)
{
	DIR				*dp;
	struct dirent	*entry;
	int				ret_val;
	struct stat		file_stat;

	ret_val = 0;
	dp = opendir(".");
	entry = readdir(dp);
	while (entry)
	{
		stat(entry->d_name, &file_stat);
		if (S_ISDIR(file_stat.st_mode))
			ret_val++;
		entry = readdir(dp);
	}
	closedir(dp);
	return (ret_val);
}

char	**cur_dir_onlydir_list(void)
{
	DIR				*dp;
	struct dirent	*entry;
	int				i;
	char			**ret_list;
	struct stat		file_stat;

	ret_list = ft_calloc(cur_dir_onlydir_len() + 1, sizeof(char *));
	i = 0;
	dp = opendir(".");
	entry = readdir(dp);
	while (entry)
	{
		stat(entry->d_name, &file_stat);
		if (S_ISDIR(file_stat.st_mode))
		{
			ret_list[i] = malloc(ft_strlen(entry->d_name) + 2);
			ft_strlcpy(ret_list[i], entry->d_name, \
						ft_strlen(entry->d_name) + 2);
			ft_strlcat(ret_list[i], "/", ft_strlen(entry->d_name) + 2);
			i++;
		}
		entry = readdir(dp);
	}
	closedir(dp);
	return (ret_list);
}
