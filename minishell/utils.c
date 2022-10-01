/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:28:32 by dham              #+#    #+#             */
/*   Updated: 2022/10/01 22:06:37 by dham             ###   ########.fr       */
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
	return (-1);
}

int	ft_isquotes(int ch)
{
	if (ch == '\"' || ch == '\'')
		return (1);
	return (0);
}