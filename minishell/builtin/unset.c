/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:55:27 by dham              #+#    #+#             */
/*   Updated: 2022/12/21 20:12:56 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_builtin.h"

int	ft_unset(char *name)
{
	if (name)
		del_env(name);
	return (0);
}

int	exe_unset(char **argv)
{
	
}