/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:41:06 by dham              #+#    #+#             */
/*   Updated: 2022/07/27 19:56:20 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int	readline(t_backup *buf, int fd)
{
	int	i;

	buf->len = read(fd, buf->buffer, BUFFER_SIZE);
	if (buf->len < 0)
		return (-1);
	i = 0;
	while (i < buf->len)
	{
		if (buf->buffer[i] == '\n')
			buf->newline_exist++;
		i++;
	}
	return (buf->len);
}

t_backup	*buffer_fd(t_backup **backup, int fd)
{
	t_backup	*new_node;

	new_node = *backup;
	while (new_node && new_node->fd != fd)
		new_node = new_node->next;
	if (!new_node)
	{
		new_node = malloc(sizeof(t_backup));
		if (!new_node)
			return (NULL);
		new_node->fd = fd;
		new_node->len = 0;
		new_node->newline_exist = 0;
		new_node->next = *backup;
		*backup = new_node;
	}
	return (new_node);
}

void	del_eof_buf(t_backup **list, t_backup *del_buf)
{
	t_backup	*idx;

	if (*list == del_buf)
	{
		*list = del_buf->next;
		free(del_buf);
		return ;
	}
	idx = *list;
	while (idx->next != del_buf)
		idx = idx->next;
	idx->next = del_buf->next;
	free(del_buf);
}
