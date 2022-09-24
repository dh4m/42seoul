/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:36:26 by dham              #+#    #+#             */
/*   Updated: 2022/09/24 18:06:22 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int	pos_logic_oper(char *str)
{
	char	*logic_oper;
	int		ret_pos;
	int		i;

	logic_oper = NULL;
	ret_pos = -1;
	i = 0;
	while (str[i])
	{
		if (ft_strncmp(&str[i], "&&", 2) == 0 || \
			ft_strncmp(&str[i], "||", 2) == 0)
		{
			ret_pos = i;
		}
		i++;
	}
	return (ret_pos);
}

int	parse_cmd(char *str)
{
	
}