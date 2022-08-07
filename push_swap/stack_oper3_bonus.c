/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:18:22 by dham              #+#    #+#             */
/*   Updated: 2022/07/28 11:36:12 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra(t_stack *a)
{
	if (a->nnode < 2)
		return ;
	push_stack(a, lpop_stack(a));
}

void	rrb(t_stack *b)
{
	if (b->nnode < 2)
		return ;
	push_stack(b, lpop_stack(b));
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->nnode >= 2)
		push_stack(a, lpop_stack(a));
	if (b->nnode >= 2)
		push_stack(b, lpop_stack(b));
}
