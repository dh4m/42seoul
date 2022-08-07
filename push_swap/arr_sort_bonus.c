/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sort_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:12:24 by dham              #+#    #+#             */
/*   Updated: 2022/07/27 20:55:45 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdlib.h>

static void	sort_intarr(int	*a, int n)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < n)
	{
		j = i;
		while (j > 0)
		{
			if (a[j] > a[j - 1])
				break ;
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
		}
		i++;
	}
}

int	*arr_sort(t_stack *a)
{
	int		*re_arr;
	t_node	*node;
	int		i;

	re_arr = malloc(sizeof(int) * a->nnode);
	node = a->top;
	i = 0;
	while (node)
	{
		re_arr[i] = node->val;
		node = node->prev;
		i++;
	}
	sort_intarr(re_arr, a->nnode);
	return (re_arr);
}
