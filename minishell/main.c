/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:59:02 by dham              #+#    #+#             */
/*   Updated: 2022/08/31 21:07:08 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"

int main(void)
{
	char *str;

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