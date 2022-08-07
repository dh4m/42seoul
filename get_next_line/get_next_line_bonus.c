/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:37:18 by dham              #+#    #+#             */
/*   Updated: 2022/07/13 20:23:57 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_backup	*backup;
	t_backup		*fd_buf;
	char			*re_str;
	int				len;

	fd_buf = buffer_fd(&backup, fd);
	if (!fd_buf)
		return (NULL);
	len = init_str(fd_buf, &re_str);
	if (len < 0)
		return (NULL);
	if (fd_buf->newline_exist)
		return (complete_str(fd_buf, re_str, len));
	while (readline(fd_buf, fd) == BUFFER_SIZE && !fd_buf->newline_exist)
	{
		re_str = add_buffer(re_str, fd_buf, len);
		len += fd_buf->len;
		if (!re_str)
			return (NULL);
	}
	re_str = complete_str(fd_buf, re_str, len);
	if ((!len && !fd_buf->len) || re_str == NULL)
		del_eof_buf(&backup, fd_buf);
	return (re_str);
}

int	init_str(t_backup *buf, char **dst)
{
	int	i;

	if (buf->len == 0 || buf->newline_exist)
	{
		*dst = NULL;
		return (0);
	}
	*dst = malloc(buf->len);
	if (!*dst)
		return (-1);
	i = 0;
	while (i < buf->len)
	{
		(*dst)[i] = buf->buffer[i];
		i++;
	}
	buf->len = 0;
	return (i);
}

char	*add_buffer(char *s1, t_backup *buf, int len)
{
	char	*re_str;
	int		i;

	i = 0;
	re_str = malloc(len + BUFFER_SIZE);
	if (!re_str)
		return (NULL);
	while (i < len)
	{
		re_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < BUFFER_SIZE)
	{
		re_str[i + len] = buf->buffer[i];
		i++;
	}
	free(s1);
	return (re_str);
}

char	*complete_str(t_backup *buf, char *str, int len)
{
	int		i;
	int		count;
	char	*re_str;

	if (buf->len <= 0 && !len)
		return (NULL);
	count = 0;
	while (buf->buffer[count] != '\n' && count < buf->len)
		count++;
	if (buf->buffer[count] == '\n' && ++count)
		buf->newline_exist--;
	re_str = malloc(count + len + 1);
	if (!re_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		re_str[i] = str[i];
		i++;
	}
	return (make_str(buf, str, re_str, (int [2]){len, count}));
}

char	*make_str(t_backup *buf, char *str, char *re_str, int arg[2])
{
	int	i;
	int	len;
	int	count;

	len = arg[0];
	count = arg[1];
	i = 0;
	while (i < count)
	{
		re_str[i + len] = buf->buffer[i];
		i++;
	}
	re_str[count + len] = 0;
	i = 0;
	while (i < buf->len - count)
	{
		buf->buffer[i] = buf->buffer[i + count];
		i++;
	}
	buf->len = buf->len - count;
	free(str);
	return (re_str);
}
