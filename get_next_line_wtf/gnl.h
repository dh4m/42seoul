/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:05:10 by dham              #+#    #+#             */
/*   Updated: 2023/10/30 22:27:17 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>


int add_char(char **str, char *buf, int *len, int idx);
char	*get_next_line(int fd);
int ft_strcpy(char *a, char *b);
int	shift_buf(char *buf, char *curr, int size);


#endif