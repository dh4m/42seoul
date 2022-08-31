/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandclock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:35:52 by dham              #+#    #+#             */
/*   Updated: 2022/08/31 13:59:26 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sandclock(t_stack *a, t_stack *b)
{
	int	gap;

	if (a->nnode >= 300)
		gap = 36;
	else if (a->nnode >= 100)
		gap = 15;
	else
		gap = 10;
	transfer_b(a, b, gap);
	transfer_a(a, b, b->nnode - 1);
}

void	transfer_b(t_stack *a, t_stack *b, int gap)
{
	while (a->top)
	{
		if (a->top->val < b->nnode)
			pb(a, b);
		else if (b->nnode <= a->top->val && a->top->val <= b->nnode + gap)
		{
			pb(a, b);
			rb(b);
		}
		else
		{
			if (a->bottom->val <= b->nnode + gap)
				rra(a);
			else
				ra(a);
		}
	}
}

void	transfer_a(t_stack *a, t_stack *b, int max)
{
	int	need;

	need = max;
	while (b->nnode)
	{
		count_pad(b, need);
		shift_num(a, b, &need);
	}
}
