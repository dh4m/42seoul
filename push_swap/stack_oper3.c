/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:18:22 by dham              #+#    #+#             */
/*   Updated: 2022/07/24 14:52:15 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rra(t_stack *a)
{
	if (a->nnode < 2)
		return ;
	push_stack(a, lpop_stack(a));
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	if (b->nnode < 2)
		return ;
	push_stack(b, lpop_stack(b));
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->nnode >= 2)
		push_stack(a, lpop_stack(a));
	if (b->nnode >= 2)
		push_stack(b, lpop_stack(b));
	if (a->nnode >= 2 || b->nnode >= 2)
		write(1, "rrr\n", 4);
}
