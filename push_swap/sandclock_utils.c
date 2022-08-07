/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandclock_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:53:03 by dham              #+#    #+#             */
/*   Updated: 2022/07/27 16:53:28 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_pad(t_stack *b, int need)
{
	t_node	*node;
	int		top_pad;
	int		bottom_pad;

	top_pad = 0;
	bottom_pad = 0;
	node = b->top;
	while (node && !(node->val == need || node->val == need - 1))
	{
		top_pad++;
		node = node->prev;
	}
	node = b->bottom;
	while (node && !(node->val == need || node->val == need - 1))
	{
		bottom_pad++;
		node = node->next;
	}
	if (top_pad <= bottom_pad)
		show_move(b, top_pad);
	else
		show_move(b, -bottom_pad);
}

void	show_move(t_stack *b, int count)
{
	int	i;

	i = 0;
	if (count >= 0)
	{
		while (i < count)
		{
			rb(b);
			i++;
		}
	}
	else
	{
		while (i < -count)
		{
			rrb(b);
			i++;
		}
	}
}

void	shift_num(t_stack *a, t_stack *b, int *need)
{
	if (b->top->val == *need)
	{
		if (a->top && a->top->val == *need - 1)
			(*need)--;
		pa(a, b);
		(*need)--;
		sort2(a);
	}
	else if (b->bottom->val == *need)
	{
		if (a->top && a->top->val == *need - 1)
			(*need)--;
		rrb(b);
		pa(a, b);
		(*need)--;
		sort2(a);
	}
	else if (b->top->val == *need - 1)
		pa(a, b);
	else if (b->bottom->val == *need - 1)
	{
		rrb(b);
		pa(a, b);
	}
}
