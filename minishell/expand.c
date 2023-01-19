/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:57:47 by dham              #+#    #+#             */
/*   Updated: 2023/01/19 13:21:45 by dham             ###   ########.fr       */
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

int	dollor_len(char *str)
{
	int	len;

	len = 1;
	if (str[1] == '?')
		return (1);
	if (str[1] != '_' && !ft_isalpha(str[1]))
		return (0);
	while (str[len] && (ft_isalnum(str[len]) || str[len] == '_'))
	{
		len++;
	}
	return (len - 1);
}

char	*dollor_search(char *str, char *search)
{
	int	bracket;

	bracket = 0;
	while (*str)
	{
		if (*str == '\\')
			str++;
		else if (*str == '"')
			bracket = (bracket == 0);
		else if (str >= search && *str == '$' && dollor_len(str))
			return (str);
		else if (!bracket && *str == '\'')
			str = ft_strchr(str + 1, '\'');
		str++;
	}
	return (0);
}

char	*expansion(char *str)
{
	char	*pos;
	int		idx;
	char	*rep;
	char	*name;

	pos = dollor_search(str, str);
	while (pos)
	{
		name = ft_substr(pos, 1, dollor_len(pos));
		if (search_env(name))
			rep = insert_escape(search_env(name)->value, \
								BACKSLASH_E | QUOTES_E);
		else if (*name == '?')
			rep = ft_itoa(g_info.ret_val);
		else
			rep = ft_calloc(1, sizeof(char));
		idx = pos - str;
		str = strreplace(str, pos - str, pos - str + dollor_len(pos), rep);
		pos = &str[idx];
		free(name);
		pos = dollor_search(str, pos + ft_strlen(rep));
		free(rep);
	}
	return (str);
}

char	*remove_quote(char *str)
{
	int		i;
	char	quote;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			i++;
		else if (str[i] == '"' || str[i] == '\'')
		{
			quote = str[i];
			str = strreplace(str, i, i, "");
			while (str[i] != quote)
				i++;
			str = strreplace(str, i, i, "");
			continue ;
		}
		i++;
	}
	return (str);
}

void	quote_proc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		argv[i] = remove_quote(argv[i]);
		i++;
	}
}
