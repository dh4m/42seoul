/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preproc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:38:50 by dham              #+#    #+#             */
/*   Updated: 2022/07/27 16:49:59 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	preprocess(t_stack *a, int *arr)
{
	int		i;
	int		num;
	t_node	*node;

	i = 0;
	while (i < a->nnode)
	{
		num = arr[i];
		node = a->top;
		while (node->val != num)
			node = node->prev;
		node->val = i;
		i++;
	}
}
