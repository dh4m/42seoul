/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:56:56 by dham              #+#    #+#             */
/*   Updated: 2022/09/11 20:09:15 by dham             ###   ########.fr       */
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

typedef struct s_node
{
	char			*name;
	char			*value;
	struct s_node	*next;
}	t_node;

typedef struct s_info
{
	t_node	*env;
	int		ret_val;
}	t_info;


void	exit_prompt(void);

#endif