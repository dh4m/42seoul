/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:59:23 by dham              #+#    #+#             */
/*   Updated: 2023/01/23 20:04:56 by dham             ###   ########.fr       */
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

int	pattern_matching(char *str, char **pattern, int front, int back)
{
	int		i;
	char	*ptr;

	if ((*pattern == NULL || **pattern != '.') && *str == '.')
		return (0);
	if (front && !front_matching(str, pattern[0]))
		return (0);
	i = 0;
	ptr = str;
	while (pattern[i])
	{
		ptr = ft_strnstr(ptr, pattern[i], ft_strlen(ptr));
		if (!ptr)
			return (0);
		i++;
	}
	if (back && !back_matching(ptr, pattern[i - 1]))
		return (0);
	return (1);
}

int	check_star(char *str)
{
	while (*str)
	{
		if (*str == '\\')
			str++;
		else if (*str == '"' || *str == '\'')
			str = ft_strchr(str + 1, *str);
		if (*str == '*')
			return (1);
		str++;
	}
	return (0);
}

char	*wild_filelist(char *p_str)
{
	char	*ret_str;
	char	**pattern;
	char	**dir_list;
	int		i;

	ret_str = ft_calloc(1, 1);
	pattern = shell_split(p_str, '*');
	quote_proc(pattern);
	escape_proc(pattern);
	if (p_str[ft_strlen(p_str) - 1] == '/')
		dir_list = cur_dir_onlydir_list();
	else
		dir_list = cur_dir_list();
	i = -1;
	while (dir_list[++i])
	{
		if (*p_str != '.' && dir_list[i][0] == '.')
			continue ;
		if (pattern_matching(dir_list[i], pattern, \
			(p_str[0] != '*'), (p_str[ft_strlen(p_str) - 1] != '*')))
			ret_str = filelist_join(ret_str, dir_list[i]);
	}
	free_path_list(pattern);
	free_path_list(dir_list);
	return (ret_str);
}

void	wildcard(char **str)
{
	int		i;
	char	*filelist;

	i = 0;
	while (str[i])
	{
		if (check_star(str[i]))
		{
			filelist = wild_filelist(str[i]);
			if (!*filelist)
				free(filelist);
			else
			{
				free(str[i]);
				str[i] = filelist;
			}
		}
		i++;
	}
}
