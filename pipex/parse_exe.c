/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:09:30 by dham              #+#    #+#             */
/*   Updated: 2022/07/20 14:31:21 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <unistd.h>

void	execute_cmd(char *cmd, char *envp[])
{
	char	**argv;
	char	*cmd_str;

	argv = ft_split(cmd, ' ');
	if (ft_strchr(argv[0], '/'))
	{
		execve(argv[0], argv, envp);
		command_err(argv[0]);
		free_path_list(argv);
		exit(-1);
	}
	cmd_str = search_cmd(argv[0], envp);
	execve(cmd_str, argv, envp);
	free(cmd_str);
	command_err(argv[0]);
	free_path_list(argv);
	exit(-1);
}

char	*search_cmd(char *cmd, char *envp[])
{
	char	**path;
	char	*ret_path;
	int		i;

	i = 0;
	path = path_list(envp);
	ret_path = path_join(path[i], cmd);
	while (access(ret_path, F_OK) == -1 && path[i + 1])
	{
		free(ret_path);
		i++;
		ret_path = path_join(path[i], cmd);
	}
	free_path_list(path);
	return (ret_path);
}

char	*path_join(char *path, char *cmd)
{
	char	*ret_str;
	int		path_len;
	int		cmd_len;

	path_len = ft_strlen(path);
	cmd_len = ft_strlen(cmd);
	ret_str = malloc(path_len + cmd_len + 2);
	if (!ret_str)
		error_exit();
	ft_strlcpy(ret_str, path, path_len + 1);
	ft_strlcat(ret_str, "/", path_len + 2);
	ft_strlcat(ret_str, cmd, path_len + cmd_len + 2);
	return (ret_str);
}

char	**path_list(char *envp[])
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (ft_split(&envp[i][5], ':'));
}

void	free_path_list(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}
