/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:36:26 by dham              #+#    #+#             */
/*   Updated: 2022/09/25 14:59:30 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int	pos_logic_oper(char *str, int len)
{
	int		ret_pos;
	int		i;

	ret_pos = -1;
	i = 0;
	while (i < len)
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

int	parse_cmd(char *str, int len)
{
	
}