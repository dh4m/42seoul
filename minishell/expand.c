/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:57:47 by dham              #+#    #+#             */
/*   Updated: 2022/12/23 16:08:20 by dham             ###   ########.fr       */
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
			rep = search_env(name)->value;
		else if (*name == '?')
			rep = ft_itoa(g_info.ret_val);
		else
			rep = "";
		str = strreplace(str, pos - str, pos - str + dollor_len(pos), rep);
		if (*name == '?')
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
		if (str[i] == '"' || str[i] == '\'')
		{
			quote = str[i];
			str = strreplace(str, i, i, "");
			while (str[i] != quote)
				i++;
			str = strreplace(str, i, i, "");
			continue;
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