/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:21:11 by dham              #+#    #+#             */
/*   Updated: 2023/01/13 15:45:25 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "builtin/ft_builtin.h"
#include "signal/ft_signal.h"
#include "minishell.h"
#include <fcntl.h>

char	*dollor_search_heredoc(char *str)
{
	while (*str)
	{
		if (*str == '$' && dollor_len(str))
			return (str);
		str++;
	}
	return (0);
}

char	*expansion_heredoc(char *str)
{
	char	*pos;
	char	*rep;
	char	*name;

	pos = dollor_search_heredoc(str);
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
		pos = dollor_search_heredoc(str);
	}
	return (str);
}