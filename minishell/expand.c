/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:57:47 by dham              #+#    #+#             */
/*   Updated: 2023/01/14 22:52:57 by dham             ###   ########.fr       */
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

char	*insert_escape(char *str)
{
	int		i;
	char	*ret_str;

	i = 0;
	ret_str = ft_strdup(str);
	while (ret_str[i])
	{
		if (ret_str[i] == '\"')
		{
			ret_str = strreplace(ret_str, i, i, "\\\"");
			i++;
		}
		else if (ret_str[i] == '\'')
		{
			ret_str = strreplace(ret_str, i, i, "\\\'");
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
		//
	}
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
	while (ft_isalpha(str[len]) || str[len] == '_')
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
		if (*str == '"')
			bracket = (bracket == 0);
		if (*str == '$' && dollor_len(str))
			return (str);
		if (!bracket && *str == '\'')
			str = ft_strchr(str + 1, '\'');
		str++;
	}
	return (0);
}

char	*expansion(char *str)
{
	char	*pos;
	char	*rep;
	char	*name;

	pos = dollor_search(str);
	while (pos)
	{
		name = ft_substr(pos, 1, dollor_len(pos));
		if (search_env(name))
		{
			rep = search_env(name)->value;
			rep = insert_escape(rep);
		}
		else if (*name == '?')
			rep = ft_itoa(g_info.ret_val);
		else
			rep = ft_calloc(1, sizeof(char));
		str = strreplace(str, pos - str, pos - str + dollor_len(pos), rep);
		free(rep);
		free(name);
		pos = dollor_search(str);
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
		if (str[i] == '\030')
			i++;
		if (str[i] == '"' || str[i] == '\'')
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
