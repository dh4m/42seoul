/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:55:31 by dham              #+#    #+#             */
/*   Updated: 2022/07/28 11:35:55 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->nnode < 2)
		return ;
	temp = a->top->val;
	a->top->val = a->top->prev->val;
	a->top->prev->val = temp;
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->nnode < 2)
		return ;
	temp = b->top->val;
	b->top->val = b->top->prev->val;
	b->top->prev->val = temp;
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
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->nnode == 0)
		return ;
	push_stack(a, pop_stack(b));
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->nnode == 0)
		return ;
	push_stack(b, pop_stack(a));
}
