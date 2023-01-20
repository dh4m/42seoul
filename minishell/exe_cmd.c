/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:32:18 by dham              #+#    #+#             */
/*   Updated: 2023/01/20 15:57:48 by dham             ###   ########.fr       */
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

void	filepath_exit(char *path)
{
	if (access(path, F_OK) == 0)
		exit(126);
	exit(127);
}

int	command_err(const char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd((char *)cmd, 2);
	ft_putstr_fd("\n", 2);
	g_info.ret_val = 127;
	return (0);
}

static int	is_builtin(char *str)
{
	return (str && \
			(ft_strncmp("cd", str, 3) == 0 || \
			ft_strncmp("echo", str, 5) == 0 || \
			ft_strncmp("env", str, 4) == 0 || \
			ft_strncmp("exit", str, 5) == 0 || \
			ft_strncmp("export", str, 7) == 0 || \
			ft_strncmp("pwd", str, 4) == 0 || \
			ft_strncmp("unset", str, 6) == 0));
}

int	exe_cmd_fork(t_astnode *node)
{
	char	**argv;
	char	*cmd_str;
	char	**envp;

	argv = get_argv(node);
	envp = env_list_make();
	if (is_builtin(argv[0]))
	{
		exe_builtin(argv, node, 0, 1);
		exit(g_info.ret_val);
	}
	if (!io_fd_set(node))
		exit(1);
	if (!argv[0])
		exit(0);
	if (ft_strchr(argv[0], '/'))
	{
		execve(argv[0], argv, envp);
		common_error(argv[0]);
		filepath_exit(argv[0]);
	}
	cmd_str = search_cmd(argv[0], envp);
	execve(cmd_str, argv, envp);
	exit(g_info.ret_val);
}

int	exe_pure_cmd(t_astnode *node, int parent)
{
	char	**argv;
	int		fd_backup[2];
	int		pid;
	int		ret_val;

	fd_backup[0] = dup(STDIN_FILENO);
	fd_backup[1] = dup(STDOUT_FILENO);
	argv = get_argv(node);
	if (argv && is_builtin(argv[0]))
		exe_builtin(argv, node, parent, 0);
	else
	{
		pid = exe_ast_cmd(node, 0, 1, -1);
		waitpid(pid, &ret_val, 0);
		if (WIFEXITED(ret_val))
			g_info.ret_val = WEXITSTATUS(ret_val);
		else
			recieve_signal(ret_val);
	}
	free_path_list(argv);
	redirect_reset(fd_backup);
	return (g_info.ret_val);
}
