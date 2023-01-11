/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:02:32 by dham              #+#    #+#             */
/*   Updated: 2023/01/11 16:27:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_builtin.h"
#include "libft.h"
#include <stdio.h>

void	exe_builtin(char **argv, t_astnode *node, int parents)
{
	int	(*const func[6])(char **) = {exe_cd, exe_echo, exe_env, \
										exe_export, exe_pwd, exe_unset};
	const char	*func_name[6] = {"cd", "echo", "env", \
								"export", "pwd", "unset"};
	const int	cmd_len = ft_strlen(argv[0]);
	int			i;

	if (!redirect_set(node, 0))
		return ;
	i = 0;
	if (ft_strncmp(argv[0], "exit", cmd_len + 1) == 0)
	{
		exe_exit(argv, parents);
		return ;
	}
	while (i < NUM_BUILTIN)
	{
		if (ft_strncmp(argv[0], func_name[i], cmd_len + 1) == 0)
		{
			func[i](argv);
			return ;
		}
		i++;
	}
	ft_putstr_fd("Unknown Error in Builtin!!!!\n", 2);
	exit (127);
}
