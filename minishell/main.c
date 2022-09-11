/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:59:02 by dham              #+#    #+#             */
/*   Updated: 2022/09/11 17:50:37 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "builtin/ft_builtin.h"
#include "signal/ft_signal.h"
#include "minishell.h"

int main(void)
{
	char *str;
	
	ft_signal_set();
	while (1)
	{
		str = readline("minishell$ ");
		if (str && *str != '\n' && *str != 0)
		{
			printf("%s\n", str);
			add_history(str);
		}
		else if (!str)
		{
			exit_prompt();
			free(str);
			break;
		}
		free(str);
	}
	return (0);
}

void	exit_prompt(void)
{
	;
}
