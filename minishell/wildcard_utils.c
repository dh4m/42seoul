/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:52:31 by dham              #+#    #+#             */
/*   Updated: 2023/01/12 20:32:54 by dham             ###   ########.fr       */
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

char	*filelist_join(char *str, char *file)
{
	char		*ret_str;
	const int	len = ft_strlen(str) + ft_strlen(file) + 2;

	ret_str = malloc(len);
	ft_strlcpy(ret_str, str, len);
	ft_strlcat(ret_str, " ", len);
	ft_strlcat(ret_str, file, len);
	free(str);
	return (ret_str);
}

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
		if (ft_strncmp(entry->d_name, "..", ft_strlen(entry->d_name)))
		{
			ret_list[i] = malloc(ft_strlen(entry->d_name) + 1);
			ft_strlcpy(ret_list[i], entry->d_name, \
						ft_strlen(entry->d_name) + 1);
			i++;
		}
		entry = readdir(dp);
	}
	ret_list[i] = NULL;
	closedir(dp);
	return (ret_list);
}
