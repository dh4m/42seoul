/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:21:11 by dham              #+#    #+#             */
/*   Updated: 2023/01/17 19:44:08 by dham             ###   ########.fr       */
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
#include "get_next_line/get_next_line.h"
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
	int		idx;
	char	*pos;
	char	*rep;
	char	*name;

	pos = dollor_search_heredoc(str);
	while (pos)
	{
		name = ft_substr(pos, 1, dollor_len(pos));
		if (search_env(name))
			rep = ft_strdup(search_env(name)->value);
		else if (*name == '?')
			rep = ft_itoa(g_info.ret_val);
		else
			rep = ft_calloc(1, sizeof(char));
		idx = pos - str;
		str = strreplace(str, pos - str, pos - str + dollor_len(pos), rep);
		pos = &str[idx];
		free(rep);
		free(name);
		pos = dollor_search_heredoc(pos + dollor_len(pos));
	}
	return (str);
}

int	heredoc_expansion_write(int fd, int fd_original)
{
	char		*str;

	while (1)
	{
		str = get_next_line(fd_original);
		if (!str)
			break ;
		str = expansion_heredoc(str);
		write(fd, str, ft_strlen(str));
		free(str);
	}
	return (1);
}

int	expansion_heredoc_file(int fd_original)
{
	char	*temp_name;
	int		fd_w;
	int		fd;

	temp_name = make_heredoc_temp_name();
	fd_w = open(temp_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	fd = open(temp_name, O_RDONLY);
	unlink(temp_name);
	heredoc_expansion_write(fd_w, fd_original);
	free(temp_name);
	close(fd_w);
	close(fd_original);
	return (fd);
}