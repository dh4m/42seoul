/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:56:56 by dham              #+#    #+#             */
/*   Updated: 2022/12/23 14:15:18 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
# define RANDSTR_LEN 8

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

typedef struct s_strnode
{
	char				*str;
	int					type;
	struct s_strnode	*next;
}	t_strnode;

typedef struct s_strlist
{
	t_strnode	prenode;
	int			node_num;
}	t_strlist;

typedef struct s_astnode
{
	int					type;
//	int					breket;
	t_strlist			redi;
	t_strlist			cmd;
	struct s_astnode	*left;
	struct s_astnode	*right;
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

int			make_ast(t_cmdlist *cmdlist, t_ast *ast);
t_astnode	*make_pipeline(t_cmdlist *cmdlist);
t_astnode	*make_node(t_cmdlist *cmdlist);
t_astnode	*make_oper_node(t_cmdlist *cmdlist);
void		clear_ast(t_astnode *root);

t_astnode	*init_astnode(void);
int 		avail_node(t_cmdnode *node);
int			is_redirection(int type);
void		clear_strlist(t_strlist *list);

int			cmd_proc(t_cmdlist *cmdlist, t_astnode *node);
int			redir_proc(t_cmdlist *cmdlist, t_astnode *node);
void		add_strnode(char *str, int type, t_strlist *list);

int			heredoc_proc(char *end_flag, t_strlist *list);
char		*make_heredoc_temp_name(void);

t_astnode	*bracket_tree(t_cmdlist *list);
int			make_bracket_ast(t_cmdlist *cmdlist, t_ast *ast);
t_astnode	*make_bracket_pipeline(t_cmdlist *cmdlist);
t_astnode	*make_bracket_node(t_cmdlist *cmdlist);

int			syntax_error(int ret_val);
int			node_syntax_error(int ret_val, t_astnode *need_free);
int			node_return(int ret_val, t_astnode *need_free);
void		redi_error(char *name);

void		exe_ast(t_astnode *node, int input, int output);

void		exe_ast_and(t_astnode *left_node, t_astnode *right_node);
void		exe_ast_or(t_astnode *left_node, t_astnode *right_node);
void		exe_ast_pipe(t_astnode *left_node, t_astnode *right_node, int input);
int			exe_ast_cmd(t_astnode *node, int input, int output, int remain);
int			exe_ast_bracket(t_astnode *node, int input, int output);

void		input_set(int input);
void		output_set(int output);
void		re_in_set(t_strnode *red_node);
void		re_out_set(t_strnode *red_node);
void		redirect_set(t_astnode *node);
void		redirect_reset(int backup[2]);

int			exe_cmd(t_astnode *node);
int			exe_cmd_fork(t_astnode *node);
int			exe_pure_cmd(t_astnode *node);

char		*search_cmd(char *cmd, char *envp[]);
char		*path_join(char *path, char *cmd);
char		**path_list(char *envp[]);
void		free_path_list(char **path);

size_t		list_strlen(t_strlist *list);
char		*list_to_str(t_strlist *list);
char		*strreplace(char *str, size_t start, size_t end, char *rep);
char		**get_argv(t_astnode *node);

char		**shell_split(char const *s, char c);

char		*remove_quote(char *str);
void		quote_proc(char **argv);
char		*expansion(char *str);

#endif