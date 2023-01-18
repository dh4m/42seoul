/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:56:56 by dham              #+#    #+#             */
/*   Updated: 2023/01/18 19:55:21 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# define RANDSTR_LEN 8

# define BACKSLASH_E 1
# define QUOTES_E 2
# define SPACE_E 4

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
	RE_HEREDOC_EXPAND,
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

typedef union u_content
{
	char	*str;
	int		fd;
}	t_content;

typedef struct s_strnode
{
	t_content			content;
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

int			get_token(t_strbuff *buff, t_cmdnode **cur_node);
int			cmd_len(char *cmd);

int			make_ast(t_cmdlist *cmdlist, t_ast *ast);
t_astnode	*make_pipeline(t_cmdlist *cmdlist);
t_astnode	*make_node(t_cmdlist *cmdlist);
t_astnode	*make_oper_node(t_cmdlist *cmdlist);
void		clear_ast(t_astnode *root);

t_astnode	*init_astnode(void);
int			avail_node(t_cmdnode *node);
int			is_redirection(int type);
void		clear_strlist(t_strlist *list);

int			cmd_proc(t_cmdlist *cmdlist, t_astnode *node);
int			redir_proc(t_cmdlist *cmdlist, t_astnode *node);
void		add_strnode(char *str, int heredoc_fd, int type, t_strlist *list);

int			heredoc_proc(char *end_flag, t_strlist *list);
char		*make_heredoc_temp_name(void);

t_astnode	*bracket_tree(t_cmdlist *list);
int			make_bracket_ast(t_cmdlist *cmdlist, t_ast *ast);
t_astnode	*make_bracket_pipeline(t_cmdlist *cmdlist);
t_astnode	*make_bracket_node(t_cmdlist *cmdlist);

int			node_syntax_error(int ret_val, \
								t_astnode *need_free, t_cmdnode *node);
int			node_free_return(int ret_val, t_astnode *need_free);
int			redi_error(char *name);
int			ambiguous_error(char *name);

void		exe_ast(t_astnode *node, int input, int output, int parent);

void		exe_ast_and(t_astnode *left_node, \
							t_astnode *right_node, int parent);
void		exe_ast_or(t_astnode *left_node, t_astnode *right_node, int parent);
void		exe_ast_pipe(t_astnode *left_node, \
							t_astnode *right_node, int input);
int			exe_ast_cmd(t_astnode *node, int input, int output, int remain);
int			exe_ast_bracket(t_astnode *node, int input, int output, int remain);

int			re_in_set(t_strnode *red_node);
int			re_out_set(t_strnode *red_node);
int			redirect_set(t_astnode *node);
void		redirect_reset(int backup[2]);

int			exe_cmd(t_astnode *node);
int			exe_cmd_fork(t_astnode *node);
int			exe_pure_cmd(t_astnode *node, int parent);

char		*search_cmd(char *cmd, char *envp[]);
char		*path_join(char *path, char *cmd);
char		**path_list(char *envp[]);
void		free_path_list(char **path);

size_t		list_strlen(t_strlist *list);
char		*list_to_str(t_strlist *list);
char		*strreplace(char *str, size_t start, size_t end, char *rep);
char		**get_argv(t_astnode *node);
char		*filename_expansion(char *str);

char		**shell_split(char const *s, char c);

char		*insert_escape(char *str, unsigned char flag);
void		escape_proc(char **argv);
char		*remove_escape(char *str);
int			dollor_len(char *str);
char		*remove_quote(char *str);
void		quote_proc(char **argv);
char		*expansion(char *str);

char		*expansion_heredoc(char *str);
int			expansion_heredoc_file(int fd_original);

void		turn_off_show_signal(void);
void		turn_on_show_signal(void);

void		wildcard(char **str);

char		*filelist_join(char *str, char *file);
int			front_matching(char *str, char *pattern);
int			back_matching(char *str, char *pattern);

char		**cur_dir_list(void);
char		**cur_dir_onlydir_list(void);

void		input_set(int input);
void		output_set(int output);
int			io_fd_set(t_astnode *node);
int			re_in_set_fd(t_strnode *red_node);
int			re_out_set_fd(t_strnode *red_node);

#endif