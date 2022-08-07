/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:18:19 by dham              #+#    #+#             */
/*   Updated: 2022/07/24 14:52:17 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ra(t_stack *a)
{
	if (a->nnode < 2)
		return ;
	lpush_stack(a, pop_stack(a));
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (b->nnode < 2)
		return ;
	lpush_stack(b, pop_stack(b));
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->nnode >= 2)
		lpush_stack(a, pop_stack(a));
	if (b->nnode >= 2)
		lpush_stack(b, pop_stack(b));
	if (a->nnode >= 2 || b->nnode >= 2)
		write(1, "rr\n", 3);
}
