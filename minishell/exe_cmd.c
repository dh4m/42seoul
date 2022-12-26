/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:32:18 by dham              #+#    #+#             */
/*   Updated: 2022/12/26 17:17:54 by dham             ###   ########.fr       */
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

int	exe_cmd_fork(t_astnode *node)
{
	char	**argv;
	char	*cmd_str;
	char	**envp;

	redirect_set(node);
	argv = get_argv(node);
	envp = env_list_make();
	if (!argv || !argv[0])
		exit(0);
	if (ft_strchr(argv[0], '/'))
	{
		execve(argv[0], argv, envp);
		command_err(argv[0]);
		exit(127);
	}
	else if (is_builtin(argv[0]))
	{
		exe_builtin(argv, 0);
		exit(g_info.ret_val);
	}
	cmd_str = search_cmd(argv[0], envp);
	execve(cmd_str, argv, envp);
	command_err(argv[0]);
	exit(127);
}

int	exe_pure_cmd(t_astnode *node)//////ㅣ미완성 명령어 하나도 없을 때  처리 전부
{
	char	**argv;
	int		fd_backup[2];
	int		pid;
	int		ret_val;

	fd_backup[0] = dup(STDIN_FILENO);
	fd_backup[1] = dup(STDOUT_FILENO);
	redirect_set(node);
	argv = get_argv(node);
	if (argv && argv[0] && is_builtin(argv[0]))
		exe_builtin(argv, 1);
	else if (node->type == BRACKET_OPEN || (argv && argv[0])) // 여기 다시 고려
	{
		pid = exe_ast_cmd(node, 0, 1, -1);
		waitpid(pid, &ret_val, 0);
		if (WIFEXITED(ret_val))
			g_info.ret_val = WEXITSTATUS(ret_val);
		else
			g_info.ret_val = WTERMSIG(ret_val);
	}
	free_path_list(argv);
	redirect_reset(fd_backup);
	return (g_info.ret_val);
}

