/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:32:18 by dham              #+#    #+#             */
/*   Updated: 2022/12/20 14:43:18 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include "builtin/ft_builtin.h"
#include "signal/ft_signal.h"
#include "minishell.h"

static void	command_err(const char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd((char *)cmd, 2);
	ft_putstr_fd("\n", 2);
}

static int	is_builtin(char *str)
{
	return (ft_strncmp("cd", str, 3) == 0 || \
			ft_strncmp("echo", str, 5) == 0 || \
			ft_strncmp("env", str, 4) == 0 || \
			ft_strncmp("exit", str, 5) == 0 || \
			ft_strncmp("export", str, 7) == 0 || \
			ft_strncmp("pwd", str, 4) == 0 || \
			ft_strncmp("unset", str, 6) == 0);
}

static int	is_parents(char *str)
{
	return (ft_strncmp("cd", str, 3) == 0 || \
			ft_strncmp("echo", str, 5) == 0 || \
			ft_strncmp("env", str, 4) == 0 || \
			ft_strncmp("exit", str, 5) == 0 || \
			ft_strncmp("export", str, 7) == 0 || \
			ft_strncmp("pwd", str, 4) == 0 || \
			ft_strncmp("unset", str, 6) == 0);
}

int	exe_cmd_fork(t_astnode *node)
{
	char	**argv;
	char	*cmd_str;
	char	**envp;

	redirect_set(node);
	argv = get_argv(node);
	envp = env_list_make();
	if (ft_strchr(argv[0], '/'))
	{
		execve(argv[0], argv, envp);
		command_err(argv[0]);
		free_path_list(argv);
		exit(127);
	}
	/*
	else if (is_builtin(argv[0]))
		; // builtin
	*/
	cmd_str = search_cmd(argv[0], envp);
	execve(cmd_str, argv, envp);
	free(cmd_str);
	command_err(argv[0]);
	free_path_list(argv);
	exit(127);
}
/*
int	exe_pure_cmd(t_astnode *node)
{
	char	**argv;
	char	*cmd_str;
	char	**envp;
	int		fd_backup[2];

	fd_backup[0] = dup(STDIN_FILENO);
	fd_backup[1] = dup(STDOUT_FILENO);
	re_in_set(node);
	re_out_set(node);
	argv = get_argv(node);
	envp = env_list_make();
	if (is_parents(argv[0]))
		; // builtin
}
*/
