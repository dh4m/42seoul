/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:57:47 by dham              #+#    #+#             */
/*   Updated: 2023/01/18 20:39:41 by dham             ###   ########.fr       */
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

char	*make_escape_character(char *str, int idx, char ch)
{
	char	*ret_str;
	char	escape_char[3];

	escape_char[0] = '\\';
	escape_char[1] = ch;
	escape_char[2] = 0;
	ret_str = strreplace(str, idx, idx, escape_char);
	return (ret_str);
}

char	*insert_escape(char *str, unsigned char flag)
{
	int		i;
	char	*ret_str;

	i = 0;
	ret_str = ft_strdup(str);
	while (ret_str[i])
	{
		if (((ret_str[i] == '\"' || ret_str[i] == '\'') && (flag & QUOTES_E)) \
			|| (ret_str[i] == ' ' && (flag & SPACE_E)) \
			|| (ret_str[i] == '\\' && (flag & BACKSLASH_E)))
		{
			ret_str = make_escape_character(ret_str, i, ret_str[i]);
			i++;
		}
		i++;
	}
	return (ret_str);
}

char	*remove_escape(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			str = strreplace(str, i, i, "");
		i++;
	}
	return (str);
}

void	escape_proc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		argv[i] = remove_escape(argv[i]);
		i++;
	}
}

int	dollor_len(char *str)
{
	int	len;

	len = 1;
	if (str[len] == '?')
		return (1);
	while (str[len] && ft_isalpha(str[len]) || str[len] == '_')
	{
		len++;
	}
	return (len - 1);
}

char	*dollor_search(char *str)
{
	int	bracket;

	bracket = 0;
	while (*str)
	{
		if (*str == '\\')
			str++;
		else if (*str == '"')
			bracket = (bracket == 0);
		else if (*str == '$' && dollor_len(str))
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

	pos = dollor_search(str);
	while (pos)
	{
		name = ft_substr(pos, 1, dollor_len(pos));
		if (search_env(name))
			rep = insert_escape(search_env(name)->value, BACKSLASH_E | QUOTES_E);
		else if (*name == '?')
			rep = ft_itoa(g_info.ret_val);
		else
			rep = ft_calloc(1, sizeof(char));
		idx = pos - str;
		str = strreplace(str, pos - str, pos - str + dollor_len(pos), rep);
		pos = &str[idx];
		free(name);
		pos = dollor_search(pos + ft_strlen(rep));
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
