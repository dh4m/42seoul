/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_general.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:21:32 by dham              #+#    #+#             */
/*   Updated: 2023/02/26 20:21:21 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

int	free_split(char **sp)
{
	int	i;

	if (!sp)
		return (1);
	i = 0;
	while (sp[i])
		free(sp[i]);
	free(sp);
	return (1);
}

char	*ft_readline(int fd)
{
	char	*ret_str;

	ret_str = get_next_line(fd);
	while (ret_str && ft_strncmp(ret_str, "\n", 2) == 0)
	{
		free(ret_str);
		ret_str = get_next_line(fd);
	}
	return (ret_str);
}