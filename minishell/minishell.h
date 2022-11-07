/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:56:56 by dham              #+#    #+#             */
/*   Updated: 2022/11/08 01:10:33 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>


enum e_type
{
	PIPE,
	AND,
	OR,
	BRACKET_OPEN,
	BRACKET_CLOSE,
	RE_IN,
	RE_APPEND,
	RE_OUT,
	RE_HEREDOC,
	DOUBLE_Q,
	SINGLE_Q,
	CMD,
	ERROR
};

typedef struct s_strbuff
{
	char	*str;
	int		len;
	int		now_read;
}	t_strbuff;

typedef struct s_cmdnode
{
	int					type;
	int					bracket;
	char				*cmd;
	struct s_cmdnode	*prev;
	struct s_cmdnode	*next;
}	t_cmdnode;

typedef struct s_cmdlist
{
	t_cmdnode	*head;
	t_cmdnode	*last;
	t_cmdnode	*current;
	int			node_num;
}	t_cmdlist;

typedef struct s_astnode
{
	int				type;
	int				breket;
	char			**redi_i;
	char			**redi_o;
	char			**cmd;
	struct s_node	*left;
	struct s_node	*right;
}	t_astnode;

typedef struct s_ast
{
	t_astnode	*root;
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

int			ft_isblank(int ch);
int			ft_isoper(char *str);
int			ft_isquotes(int ch);
int			ft_ismeta(char *str);

void		info_init(char **envp);
void		add_env(char *env_str);
void		add_only_key_env(char *env_name);
t_env		*search_env(char *name);
void		del_env(char *name);
int			valid_env_name(char *name);
int			num_of_env(void);
char		**env_list_make(void);

int			proc_cmd(char *cmd);
int			make_cmdlist(t_cmdlist *cmdlist, t_strbuff *buff);
void		init_list_ast(t_cmdlist *cmdlist, t_ast *ast);
void		add_cmdnode(t_cmdlist *cmdlist, t_cmdnode *node);
void		clear_list(t_cmdlist *cmdlist);

t_cmdnode	*get_token(t_strbuff *buff);
int			cmd_len(char *cmd);

t_astnode	*init_astnode(void);

#endif