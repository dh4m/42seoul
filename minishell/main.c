/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:59:02 by dham              #+#    #+#             */
/*   Updated: 2022/09/01 20:13:07 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include <unistd.h>

void	lineset(int what)
{
	what++;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

int main(void)
{
	char *str;
	signal(SIGINT, lineset);
	while (1)
	{
		str = readline("prompt : ");
		if (str && *str != '\n' && *str != 0)
		{
			printf("%s\n", str);
			add_history(str);
		}
		else if (!str)
			break;
		free(str);
	}
	return (0);
}
