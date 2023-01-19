/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:28:32 by dham              #+#    #+#             */
/*   Updated: 2023/01/19 13:29:44 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	ft_isblank(int ch)
{
	if (ch == ' ' || ch == '\t')
		return (1);
	return (0);
}

int	ft_oper_len(int type)
{
	if (type == AND || type == OR || type == RE_APPEND || type == RE_HEREDOC)
		return (2);
	return (1);
}

int	ft_isoper(char *str)
{
	if (!ft_strncmp(str, "&&", 2))
		return (AND);
	else if (!ft_strncmp(str, "||", 2))
		return (OR);
	else if (*str == '|')
		return (PIPE);
	else if (*str == '(')
		return (BRACKET_OPEN);
	else if (*str == ')')
		return (BRACKET_CLOSE);
	else if (!ft_strncmp(str, "<<", 2))
		return (RE_HEREDOC);
	else if (!ft_strncmp(str, ">>", 2))
		return (RE_APPEND);
	else if (*str == '<')
		return (RE_IN);
	else if (*str == '>')
		return (RE_OUT);
	return (CMD);
}

int	ft_isquotes(int ch)
{
	if (ch == '\"')
		return (DOUBLE_Q);
	if (ch == '\'')
		return (SINGLE_Q);
	return (CMD);
}

int	ft_ismeta(char *str)
{
	if (!*str || ft_isblank(*str) || ft_isoper(str) != CMD)
		return (1);
	return (0);
}
