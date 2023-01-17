/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:30:15 by dham              #+#    #+#             */
/*   Updated: 2023/01/17 18:35:52 by dham             ###   ########.fr       */
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

int	front_matching(char *str, char *pattern)
{
	return (ft_strnstr(str, pattern, ft_strlen(str)) == str);
}

int	back_matching(char *str, char *pattern)
{
	return (ft_strncmp(&str[ft_strlen(str) - ft_strlen(pattern)], pattern, \
			ft_strlen(pattern)) == 0);
}