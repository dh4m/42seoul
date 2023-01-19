/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:14:14 by dham              #+#    #+#             */
/*   Updated: 2023/01/19 13:14:46 by dham             ###   ########.fr       */
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
