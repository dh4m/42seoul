/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:36:26 by dham              #+#    #+#             */
/*   Updated: 2022/09/25 22:49:58 by dham             ###   ########.fr       */
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
			ret_pos = i;
		i++;
	}
	return (ret_pos);
}

int	parse_cmd(char *str, int len)
{
	const int	last_sep = pos_logic_oper(str, len);
	int			cmd_ret;
	char		*subcmd;

	if (last_sep == -1)
	{
		subcmd = ft_substr(str, 0, len);
		parse_pipe(subcmd);
		free(subcmd);
		return (g_info.ret_val);
	}
	cmd_ret = parse_cmd(str, last_sep);
	if ((str[last_sep] == '&' && cmd_ret != 0) || )
	{

	}
	else
	{

	}

}

int	parse_pipe(char *str)
{
	
}