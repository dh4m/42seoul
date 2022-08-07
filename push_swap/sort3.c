/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:02:07 by dham              #+#    #+#             */
/*   Updated: 2022/07/27 16:52:40 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3_only(t_stack *a, int case_num)
{
	if (case_num == 132)
	{
		rra(a);
		sa(a);
	}
	else if (case_num == 213)
		sa(a);
	else if (case_num == 231)
		rra(a);
	else if (case_num == 312)
		ra(a);
	else if (case_num == 321)
	{
		ra(a);
		sa(a);
	}
}

void	sort3_top(t_stack *a, t_stack *b, int case_num)
{
	if (case_num == 132)
	{
		pb(a, b);
		sa(a);
		pa(a, b);
	}
	else if (case_num == 213)
		sa(a);
	else if (case_num == 231)
	{
		pb(a, b);
		sa(a);
		pa(a, b);
		sa(a);
	}
	else if (case_num > 300)
	{
		sa(a);
		sort3(a, b);
	}
}

int	case_check3(t_stack *s)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = s->top->val;
	n2 = s->top->prev->val;
	n3 = s->top->prev->prev->val;
	if (n1 < n2 && n2 < n3)
		return (123);
	else if (n1 < n3 && n3 < n2)
		return (132);
	else if (n2 < n1 && n1 < n3)
		return (213);
	else if (n3 < n1 && n1 < n2)
		return (231);
	else if (n2 < n3 && n3 < n1)
		return (312);
	else
		return (321);
}

void	sort3(t_stack *a, t_stack *b)
{
	int	case_num;

	case_num = case_check3(a);
	if (a->nnode == 3)
		sort3_only(a, case_num);
	else
		sort3_top(a, b, case_num);
}
