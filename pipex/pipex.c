/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:09:07 by dham              #+#    #+#             */
/*   Updated: 2022/07/23 11:11:19 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[], char *envp[])
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argc > 5)
		main_heredoc(argc, argv, envp);
	else if (argc > 4)
		main_pipe(argc, argv, envp);
	else
		arg_err();
	return (0);
}

void	main_heredoc(int argc, char *argv[], char *envp[])
{
	int					file_fd[2];
	const t_argument	info = {argc - 1, &argv[1], envp};

	make_heredoc(argv[2]);
	file_fd[0] = open("temp_heredoc", O_RDONLY);
	if (unlink("temp_heredoc") == -1)
		error_exit();
	file_fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (file_fd[0] < 0 || file_fd[1] < 0)
		error_exit();
	execute_fork(info, 0, file_fd, file_fd[0]);
}

void	make_heredoc(char *end_flag)
{
	int		fd;
	char	*read_str;

	fd = open("temp_heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		error_exit();
	if (write(1, "pipe heredoc> ", 14) < 0)
		error_exit();
	read_str = get_next_line(0);
	while (!read_str || read_str[0] == '\n' || \
		ft_strncmp(read_str, end_flag, ft_strlen(read_str) - 1))
	{
		if (read_str && write(fd, read_str, ft_strlen(read_str)) < 0)
			error_exit();
		if (read_str && write(1, "pipe heredoc> ", 14) < 0)
			error_exit();
		free(read_str);
		read_str = get_next_line(0);
	}
	free(read_str);
	if (close(fd) == -1)
		error_exit();
}

void	main_pipe(int argc, char *argv[], char *envp[])
{
	int					file_fd[2];
	const t_argument	info = {argc, argv, envp};

	file_fd[0] = open(argv[1], O_RDONLY);
	file_fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file_fd[0] < 0 || file_fd[1] < 0)
		error_exit();
	execute_fork(info, 0, file_fd, file_fd[0]);
}

void	execute_fork(const t_argument info, int step, int file[2], int input)
{
	pid_t	pid;
	int		fd[2];

	if (step >= info.argc - 3)
		return ;
	if (step < info.argc - 4 && pipe(fd) == -1)
		error_exit();
	pid = fork();
	if (pid < 0)
		error_exit();
	if (pid == 0)
	{
		if (step < info.argc - 4 && close(fd[0]) == -1)
			error_exit();
		input_set(input);
		output_set(info, fd[1], file[1], step);
		execute_cmd(info.argv[step + 2], info.envp);
	}
	if (step < info.argc - 4 && close(fd[1]) == -1)
		error_exit();
	execute_fork(info, step + 1, file, fd[0]);
	if (close(input) == -1)
		error_exit();
	if (wait(NULL) == -1)
		error_exit();
}
