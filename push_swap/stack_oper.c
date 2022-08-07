/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:55:31 by dham              #+#    #+#             */
/*   Updated: 2022/07/24 14:52:17 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_stack *a)
{
	int	temp;

	if (a->nnode < 2)
		return ;
	temp = a->top->val;
	a->top->val = a->top->prev->val;
	a->top->prev->val = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->nnode < 2)
		return ;
	temp = b->top->val;
	b->top->val = b->top->prev->val;
	b->top->prev->val = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->nnode >= 2)
	{
		temp = a->top->val;
		a->top->val = a->top->prev->val;
		a->top->prev->val = temp;
	}
	if (b->nnode >= 2)
	{
		temp = b->top->val;
		b->top->val = b->top->prev->val;
		b->top->prev->val = temp;
	}
	if (a->nnode >= 2 || a->nnode >= 2)
		write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->nnode == 0)
		return ;
	push_stack(a, pop_stack(b));
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->nnode == 0)
		return ;
	push_stack(b, pop_stack(a));
	write(1, "pb\n", 3);
}
