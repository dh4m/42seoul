/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:55:27 by dham              #+#    #+#             */
/*   Updated: 2022/12/23 14:10:47 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_builtin.h"
#include "libft.h"

int	ft_unset(char *name)
{
	if (name)
		del_env(name);
	return (0);
}

int	exe_unset(char **argv)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (argv[++i])
	{
		if (!valid_name(argv[i]) || ft_strchr(argv[i], '='))
		{
			ft_putstr_fd("minishell: unset: '", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			err = 1;
			continue;
		}
		ft_unset(argv[i]);
	}
	if (err)
		g_info.ret_val = 1;
	else
		g_info.ret_val = 0;
	return (0);
}