/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_ctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:40:49 by dham              #+#    #+#             */
/*   Updated: 2023/01/20 18:56:04 by dham             ###   ########.fr       */
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

static void	make_rand_str(char *buf)
{
	unsigned char		temp;
	int					fd;
	int					i;
	const static char	*char_set = \
			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	fd = open("/dev/urandom", O_RDONLY);
	i = 0;
	while (i < RANDSTR_LEN)
	{
		read(fd, &temp, 1);
		temp %= 62;
		buf[i] = char_set[temp];
		i++;
	}
	buf[RANDSTR_LEN] = 0;
	close(fd);
}

int	heredoc_write(char *end_flag, int fd)
{
	char		*str;
	const char	*quotes_end = remove_escape(remove_quote(ft_strdup(end_flag)));

	ft_heredoc_signal_set();
	while (1)
	{
		str = readline("> ");
		if (!str || ft_strncmp(str, quotes_end, ft_strlen(str) + 1) == 0)
			break ;
		else if (*str == 0 && g_info.ret_val == SIGINT_CATCH)
		{
			free(str);
			g_info.ret_val = 1;
			end_heredoc_set();
			return (0);
		}
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
	}
	if (str)
		free(str);
	free((void *)quotes_end);
	end_heredoc_set();
	return (1);
}

int	heredoc_quotes(char *end_flag)
{
	int	i;

	i = 0;
	while (end_flag[i])
	{
		if (end_flag[i] == '\"' || end_flag[i] == '\'')
			return (0);
		i++;
	}
	return (1);
}

int	heredoc_proc(char *end_flag, t_strlist *list)
{
	char	*temp_name;
	int		fd_w;
	int		fd;

	temp_name = make_heredoc_temp_name();
	fd_w = open(temp_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	fd = open(temp_name, O_RDONLY);
	unlink(temp_name);
	if (!heredoc_write(end_flag, fd_w))
	{
		close(fd);
		close(fd_w);
		free(temp_name);
		return (0);
	}
	close(fd_w);
	if (heredoc_quotes(end_flag))
		add_strnode(NULL, fd, RE_HEREDOC_EXPAND, list);
	else
		add_strnode(NULL, fd, RE_HEREDOC, list);
	free(temp_name);
	return (1);
}

char	*make_heredoc_temp_name(void)
{
	char		rand_str[RANDSTR_LEN + 1];
	const char	*name = "/tmp/here_temp_";
	char		*ret_name;

	make_rand_str(rand_str);
	ret_name = ft_strjoin(name, rand_str);
	return (ret_name);
}
