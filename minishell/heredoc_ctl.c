/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_ctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:40:49 by dham              #+#    #+#             */
/*   Updated: 2022/11/15 21:55:36 by dham             ###   ########.fr       */
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
	char	temp;
	int		fd;
	int		i;

	fd = open("/dev/urandom", O_RDONLY);
	i = 0;
	while (i < RANDSTR_LEN)
	{
		read(fd, &temp, 1);
		temp = (temp % 58) + 65;
		if (temp > 90 && temp < 97)
		{
			temp + 7 + i;
		}
		buf[i] = temp;
		i++;
	}
	buf[RANDSTR_LEN] = 0;
}

int	heredoc_write(char *end_flag, int fd)
{
	char	*str;

	ft_heredoc_signal_set();
	while (1)
	{
		str = readline("> ");
		if (!str || ft_strncmp(str, end_flag, ft_strlen(str)) == 0)
			break;
		else if (*str == 0 && g_info.ret_val == 130)
		{
			free(str);
			end_heredoc_set();
			return (0);
		}
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
	}
	if (str)
		free(str);
	end_heredoc_set();
	return (1);
}

int	heredoc_proc(char *end_flag, t_strlist *list)
{
	char	*temp_name;
	int		fd_w;
	int		fd;
	char	*str;

	temp_name = make_heredoc_temp_name();
	fd_w = open(temp_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	fd = open(temp_name, O_RDONLY);
	unlink(temp_name);
	if (!heredoc_write(end_flag, fd_w))
	{
		close(fd);
		close(fd_w);
		return (0); //error
	}
	close(fd_w);
	add_strnode((char *)fd, RE_HEREDOC, list);
	free(temp_name);
	return (1);
}

char	*make_heredoc_temp_name(void)
{
	char		rand_str[RANDSTR_LEN + 1];
	const char	*name = "./temp/here_temp_";
	char		*ret_name;

	make_rand_str(rand_str);
	ret_name = ft_strjoin(name, rand_str);
	return (ret_name);
}