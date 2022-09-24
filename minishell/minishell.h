/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:56:56 by dham              #+#    #+#             */
/*   Updated: 2022/09/24 18:06:18 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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
int		valid_env_name(char *name);
int		num_of_env(void);
char	**env_list_make(void);
int		parse_cmd(char *str);

#endif