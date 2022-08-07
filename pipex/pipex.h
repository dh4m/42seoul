/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:09:14 by dham              #+#    #+#             */
/*   Updated: 2022/07/20 11:43:07 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_argument
{
	int		argc;
	char	**argv;
	char	**envp;
}	t_argument;

char	*search_cmd(char *cmd, char *envp[]);
void	execute_cmd(char *cmd, char *envp[]);
void	free_path_list(char **path);
void	execute_fork(const t_argument info, int step, int file[2], int input);
char	*path_join(char *path, char *cmd);
char	**path_list(char *envp[]);
void	main_pipe(int argc, char *argv[], char *envp[]);
void	main_heredoc(int argc, char *argv[], char *envp[]);
void	make_heredoc(char *end_flag);
void	error_exit(void);
void	command_err(const char *cmd);
void	input_set(int input_fd);
void	output_set(const t_argument info, int outfd, int outfile, int step);
void	arg_err(void);

#endif