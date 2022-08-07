/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:21:02 by dham              #+#    #+#             */
/*   Updated: 2022/07/26 16:13:29 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort5(t_stack *a, t_stack *b)
{
	int		count;

	count = 0;
	while (count < 3 && a->top)
	{
		if (a->top->val == 0 && ++count)
		{
			pb(a, b);
			if (b->nnode != 1)
				rb(b);
		}
		else if ((a->top->val == 1 || a->top->val == 2) && ++count)
			pb(a, b);
		else
			ra(a);
	}
	if (a->top->val > a->top->prev->val && b->top->val < b->top->prev->val)
		ss(a, b);
	else if (a->top->val > a->top->prev->val)
		sa(a);
	else if (b->top->val < b->top->prev->val)
		sb(b);
	while (b->top)
		pa(a, b);
}
