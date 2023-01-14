/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:05:34 by dham              #+#    #+#             */
/*   Updated: 2023/01/15 01:40:04 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

static int	word_len(const char *str, char c);
static int	word_cnt(const char *str, char c);
static int	malloc_guard(void **target, unsigned int size);

char	**shell_split(char const *s, char c)
{
	char	**re_loc;
	int		flag;
	int		idx;

	idx = 0;
	flag = 0;
	malloc_guard((void **)&re_loc, sizeof(char *) * (word_cnt(s, c) + 1));
	while (*s)
	{
		if (!flag && *s != c && ++flag)
		{
			malloc_guard((void **)&re_loc[idx], word_len(s, c) + 1);
			ft_strlcpy(re_loc[idx++], s, word_len(s, c) + 1);
		}
		else if (flag && *s == c)
			flag = 0;
		if (*s == '\\')
			s++;
		else if (*s == '"' || *s == '\'')
			s = ft_strchr(s + 1, *s);
		s++;
	}
	return (re_loc);
}

static int	word_len(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str && *str != c)
	{
		if (*str == '\\')
		{
			count++;
			str++;
		}
		else if (*str == '"' || *str == '\'')
		{
			count += ft_strchr(str + 1, *str) - str;
			str = ft_strchr(str + 1, *str);
		}
		count++;
		str++;
	}
	return (count);
}

static int	word_cnt(const char *str, char c)
{
	int	flag;
	int	count;

	if (!str)
		return (0);
	flag = 0;
	count = 0;
	while (*str)
	{
		if (!flag && *str != c)
		{
			flag = 1;
			count++;
		}
		else if (flag && *str == c)
			flag = 0;
		if (*str == '\\')
			str++;
		else if (*str == '"' || *str == '\'')
			str = ft_strchr(str + 1, *str);
		str++;
	}
	return (count);
}

static int	malloc_guard(void **target, unsigned int size)
{
	*target = ft_calloc(size, 1);
	if (!*target)
	{
		ft_putstr_fd("malloc error\n", 2);
		exit(1);
	}
	return (1);
}
