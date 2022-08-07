/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:40:43 by dham              #+#    #+#             */
/*   Updated: 2022/07/19 18:19:29 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 150
# endif

# include <stdlib.h>

typedef struct s_backup
{
	int				fd;
	char			buffer[BUFFER_SIZE];
	int				len;
	int				newline_exist;
	struct s_backup	*next;
}	t_backup;

t_backup	*buffer_fd(t_backup **backup, int fd);
void		del_eof_buf(t_backup **list, t_backup *del_buf);
int			readline(t_backup *buf, int fd);
char		*add_buffer(char *s1, t_backup *buf, int len);
int			init_str(t_backup *buf, char **dst);
char		*complete_str(t_backup *buf, char *str, int len);
char		*make_str(t_backup *buf, char *str, char *re_str, int arg[2]);

#endif