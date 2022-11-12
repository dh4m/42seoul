/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_ctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:40:49 by dham              #+#    #+#             */
/*   Updated: 2022/11/12 19:46:44 by dham             ###   ########.fr       */
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

	temp_name = make_heredoc_temp_name();
	fd = open(, O_WRONLY | O_CREAT | O_TRUNC, 0666);
}

char	*make_heredoc_temp_name(void)
{
	static int	i = -1;
	char		*num;
	const char	*name = "./temp/here_temp_";
	char		*ret_name;

	i++;
	num = ft_itoa(i);
	ret_name = ft_strjoin(name, num);
	free(num);
	return (ret_name);
}