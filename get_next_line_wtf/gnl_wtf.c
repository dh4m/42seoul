/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_wtf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:22:00 by dham              #+#    #+#             */
/*   Updated: 2023/10/30 20:12:33 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE];
	char	*ret_str;

	ret_str = NULL;
	return (readbuf(fd, buf, &ret_str) && ret_str);
}

int	readbuf(int fd, char buf[], char **str)
{
	unsigned long read_len;
	
	read_len = read(fd, buf, BUFFER_SIZE);
	(read_len == BUFFER_SIZE) && cat_str(buf, str, read_len) \
	&& readbuf(fd, buf, str);
	(read_len && read_len != BUFFER_SIZE) && cat_str(buf, str, read_len, );
	return (*str != NULL);
}

int	cat_str(char buf[], char **str, int buf_len, int str_len)
{
	int	ret;


	!*str && 
}

int	shift_buf(char *buf, char *curr, int size)
{
	!(curr - buf == BUFFER_SIZE) && (*(curr - size) = *curr);
	return ((curr - buf == BUFFER_SIZE) || shift_buf(buf, curr + 1, size));
}

int	strcpy(char *a, char *b)
{
	!*a || ((*a = *b) && strcpy(a + 1, b + 1));
	return (1);
}



