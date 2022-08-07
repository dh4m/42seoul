/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_proc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:30:53 by dham              #+#    #+#             */
/*   Updated: 2022/07/27 21:27:11 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft/libft.h"

void	arg_load(t_stack *a, int argc, char *argv[])
{
	char	**temp;
	int		i;

	i = 0;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		stack_input(a, temp);
		free_split(temp);
		i++;
	}
}

void	free_split(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	stack_input(t_stack *a, char **argv)
{
	int	i;
	int	num;

	if (argv[0] == NULL)
		error_detect();
	i = 0;
	while (argv[i])
	{
		avail_arg(argv[i]);
		num = ft_atoi(argv[i]);
		overflow_check(num, argv[i]);
		lpush_stack(a, num);
		i++;
	}
}

void	avail_arg(char *str)
{
	if (str[0] == '-' || str[0] == '+')
		str++;
	if (!*str)
		error_detect();
	while (*str)
	{
		if (!ft_isdigit(*str))
			error_detect();
		str++;
	}
}

void	overflow_check(int num, char *str)
{
	if (num != -1 && num != 0)
		return ;
	if (num == -1 && str[0] != '-')
		error_detect();
	if (num == 0 && str[0] == '-')
	{
		str++;
		while (*str)
		{
			if (*str != '0')
				error_detect();
			str++;
		}
	}
}
