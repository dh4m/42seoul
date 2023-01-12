/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:09:53 by dham              #+#    #+#             */
/*   Updated: 2023/01/12 20:44:16 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

# define NUM_BUILTIN 7
# include "../minishell.h"

typedef int (*builtin_func)(char **);

void	exe_builtin(char **argv, t_astnode *node, int parents);

int		exe_cd(char **argv);
void	cd_env_set(char *pwd, char *oldpwd);
int		ft_cd(char *path);

int		exe_echo(char **argv);
int		ft_echo(char *str);

int		exe_env(char **argv);
int		ft_env(void);

int		exe_exit(char **argv, int parents);
int		ft_exit(int code);

int		exe_export(char **argv);
int		export_env_list(void);
int		ft_export_value(char *env_str);
int		ft_export_name(char *env_str);
int		ft_export(char *env_str);

int		exe_pwd(char **argv);
int		ft_pwd(void);

int		exe_unset(char **argv);
int		ft_unset(char *name);

int		valid_name(char *str);

#endif