/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:02:32 by dham              #+#    #+#             */
/*   Updated: 2023/01/18 19:50:59 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_builtin.h"
#include "libft.h"
#include <stdio.h>

void	exe_builtin(char **argv, t_astnode *node, int parents, int pre_re)
{
	const t_builtin_func	func[6] = {exe_cd, exe_echo, exe_env, \
										exe_export, exe_pwd, exe_unset};
	const char				*func_name[6] = {"cd", "echo", "env", \
												"export", "pwd", "unset"};
	const int				cmd_len = ft_strlen(argv[0]);
	int						i;

	if ((!pre_re && !redirect_set(node)) || !io_fd_set(node))
	{
		g_info.ret_val = 1;
		return ;
	}
	i = -1;
	if (ft_strncmp(argv[0], "exit", cmd_len + 1) == 0)
	{
		exe_exit(argv, parents);
		return ;
	}
	while (++i < NUM_BUILTIN - 1)
	{
		if (ft_strncmp(argv[0], func_name[i], cmd_len + 1) == 0)
			func[i](argv);
	}
}
