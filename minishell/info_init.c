/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:41:10 by dham              #+#    #+#             */
/*   Updated: 2022/09/12 16:22:08 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "minishell.h"
#include "libft.h"

void	info_init(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		add_env(envp[i]);
		i++;
	}
}
