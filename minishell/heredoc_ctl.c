/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_ctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:40:49 by dham              #+#    #+#             */
/*   Updated: 2022/11/14 22:22:11 by dham             ###   ########.fr       */
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

int	heredoc_proc(char *end_flag, t_strlist *list)
{
	char	*temp_name;
	int		fd;
	char	*str;

	ft_heredoc_signal_set();
	temp_name = make_heredoc_temp_name(1);
	fd = open(temp_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	
}

char	*make_heredoc_temp_name(int num)
{
	static int	i = -1;
	char		*num_str;
	const char	*name = "./temp/here_temp_";
	char		*ret_name;

	if (!num)
	{
		i = 0;
		return (NULL);
	}
	i++;
	num_str = ft_itoa(i);
	ret_name = ft_strjoin(name, num_str);
	free(num_str);
	return (ret_name);
}