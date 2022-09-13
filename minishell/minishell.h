/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:56:56 by dham              #+#    #+#             */
/*   Updated: 2022/09/13 15:08:02 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_ast
{
	char			*cmd;
	struct s_ast	*right;
	struct s_ast	*left;
}	t_ast;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_info
{
	t_env	*env;
	t_env	*env_last;
	int		ret_val;
}	t_info;

extern t_info	g_info;

void	info_init(char **envp);
void	add_env(char *env_str);
void	add_only_key_env(char *env_name);
t_env	*search_env(char *name);
void	del_env(char *name);

#endif