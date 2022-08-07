/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:47:16 by dham              #+#    #+#             */
/*   Updated: 2022/07/28 11:15:13 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "checker_bonus.h"
#include <stdlib.h>

void	error_detect(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	free_stack(t_stack *s)
{
	while (s->top)
		pop_stack(s);
}

int	is_sorted(t_stack *s, int *arr)
{
	int		i;
	t_node	*node;

	node = s->top;
	i = 0;
	while (i < s->nnode)
	{
		if (arr[i] != node->val)
			return (0);
		i++;
		node = node->prev;
	}
	return (1);
}

void	dup_check(int *arr, int num)
{
	int	i;

	i = 0;
	while (i < num - 1)
	{
		if (arr[i] == arr[i + 1])
			error_detect();
		i++;
	}
}
