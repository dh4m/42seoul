/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:27:53 by dham              #+#    #+#             */
/*   Updated: 2023/01/20 17:03:22 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii_art.h"
#include "libft.h"
#include <signal.h>

void	logo(void)
{
	printf("\n");
	printf("\033[5;32m");
	printf("███╗   ███╗██╗███╗   ██╗██╗    ");
	printf("███████╗██╗  ██╗███████╗██╗     ██╗     \n");
	printf("████╗ ████║██║████╗  ██║██║    ");
	printf("██╔════╝██║  ██║██╔════╝██║     ██║     \n");
	printf("██╔████╔██║██║██╔██╗ ██║██║    ");
	printf("███████╗███████║█████╗  ██║     ██║     \n");
	printf("██║╚██╔╝██║██║██║╚██╗██║██║    ");
	printf("╚════██║██╔══██║██╔══╝  ██║     ██║     \n");
	printf("██║ ╚═╝ ██║██║██║ ╚████║██║    ");
	printf("███████║██║  ██║███████╗███████╗███████╗\n");
	printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝    ");
	printf("╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n");
	printf("\033[m");
	printf("\n");
}

void	erase_ascii(int sig)
{
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	printf("                                                         \n");
	ft_putstr_fd("\033[23A", 1);
	exit(sig + 128);
}

void	output_ascii(void)
{
	const t_ascii_func	draw[25] = {\
		ascii_1, ascii_2, ascii_3, ascii_4, ascii_5, ascii_6, ascii_7, \
		ascii_8, ascii_9, ascii_10, ascii_11, ascii_12, ascii_13, ascii_14, \
		ascii_15, ascii_16, ascii_17, ascii_18, ascii_19, ascii_20, ascii_21, \
		ascii_22, ascii_23, ascii_24, ascii_25
	};
	int					i;
	int					delay;

	i = 0;
	signal(SIGINT, erase_ascii);
	signal(SIGQUIT, erase_ascii);
	printf("\033[32m");
	while (i < 25)
	{
		draw[i]();
		if (i != 24)
			ft_putstr_fd("\033[23A", 1);
		delay = 0;
		while (delay < 50000000)
			delay++;
		i++;
	}
	printf("\033[m");
	logo();
}

void	prompt_color(int ret_code)
{
	if (ret_code == 0)
		printf("\033[1;32m");
	else
		printf("\033[1;31m");
}
