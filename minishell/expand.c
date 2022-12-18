/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:57:47 by dham              #+#    #+#             */
/*   Updated: 2022/12/18 21:36:10 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include "builtin/ft_builtin.h"
#include "signal/ft_signal.h"
#include "minishell.h"

int	dollor_len(char *str)
{
	int	len;

	len = 1;
	while (ft_isalpha(str[len]) || str[len] == '_')
	{
		len++;
	}
	return (len);
}

char	*expansion(char *str)
{
	char	*pos;
	char	*temp;
	char	*rep;
	char	*name;

	temp = ft_strdup(str);
	pos = ft_strchr(temp, '$');
	while (pos)
	{
		name = 
		rep = search_env(name)->value;
		temp = strreplace(temp, pos - temp, pos - temp + dollor_len(pos) - 1, rep);
		pos = ft_strchr(temp, '$');
	}
	return (temp);
}