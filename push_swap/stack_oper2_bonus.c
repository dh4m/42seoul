/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:18:19 by dham              #+#    #+#             */
/*   Updated: 2022/07/28 11:36:03 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_stack *a)
{
	if (a->nnode < 2)
		return ;
	lpush_stack(a, pop_stack(a));
}

void	rb(t_stack *b)
{
	if (b->nnode < 2)
		return ;
	lpush_stack(b, pop_stack(b));
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->nnode >= 2)
		lpush_stack(a, pop_stack(a));
	if (b->nnode >= 2)
		lpush_stack(b, pop_stack(b));
}
