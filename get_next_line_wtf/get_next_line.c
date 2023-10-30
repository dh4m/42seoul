/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:12:44 by dham              #+#    #+#             */
/*   Updated: 2023/10/30 22:35:35 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char *ret_str;
	int read_buf;
	int str_len;

	ret_str = NULL;
	str_len = 0;
	if (add_char(&ret_str, buf, &str_len, 0) == -1)
		return (NULL);
	if (str_len && ret_str[str_len - 1] == '\n')
		return (ret_str);
	read_buf = read(fd, buf, BUFFER_SIZE);
	if (read_buf < BUFFER_SIZE)
		buf[read_buf] = 0;
	if (read_buf == 0 && !ret_str[0])
	{
		free(ret_str);
		return (NULL);
	}
	while (add_char(&ret_str, buf, &str_len, 0) >= BUFFER_SIZE && ret_str[str_len - 1] != '\n')
	{
		read_buf = read(fd, buf, BUFFER_SIZE);
		if (read_buf < BUFFER_SIZE)
			buf[read_buf] = 0;
	}
	return (ret_str);
}

int ft_strcpy(char *a, char *b)
{
	!a || !b || !*b || ((*a = *b) && ft_strcpy(a + 1, b + 1));
	return (1);
}

int	shift_buf(char *buf, char *curr, int size)
{
	int ret_val;

	!(curr - buf > BUFFER_SIZE) && (*(curr - size) = *curr);
	((curr - buf >= BUFFER_SIZE) && (ret_val = size)) \
	|| (ret_val = shift_buf(buf, curr + 1, size));
	return (ret_val);
}

int add_char(char **str, char *buf, int *len, int idx)
{
	char *temp;

	temp = malloc(*len + 2);
	if (!temp)
	{
		free(*str);
		*str = NULL;
		return (-1);
	}
	ft_strcpy(temp, *str);
	temp[*len] = buf[idx];
	temp[*len + 1] = 0;
	free(*str);
	*str = temp;
	if (temp[*len])
		*len = *len + 1;
	if (idx >= BUFFER_SIZE - 1 || buf[idx] == '\n' || !buf[idx])
		return (shift_buf(buf, buf + idx + 1, idx + 1));
	return (add_char(str, buf, len, idx + 1));
}
