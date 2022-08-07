/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:32:45 by dham              #+#    #+#             */
/*   Updated: 2022/07/27 21:17:06 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	init_stack(t_stack *a, t_stack *b)
{
	a->nnode = 0;
	a->top = NULL;
	a->bottom = NULL;
	b->nnode = 0;
	b->top = NULL;
	b->bottom = NULL;
}

void	push_stack(t_stack *s, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->val = num;
	new_node->next = NULL;
	if (s->nnode == 0)
		s->bottom = new_node;
	new_node->prev = s->top;
	if (s->top)
		s->top->next = new_node;
	s->top = new_node;
	s->nnode++;
}

void	lpush_stack(t_stack *s, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->val = num;
	new_node->prev = NULL;
	if (s->nnode == 0)
		s->top = new_node;
	new_node->next = s->bottom;
	if (s->bottom)
		s->bottom->prev = new_node;
	s->bottom = new_node;
	s->nnode++;
}

int	pop_stack(t_stack *s)
{
	t_node	*pop_node;
	int		ret_val;

	if (s->nnode == 0)
		error_detect();
	ret_val = s->top->val;
	pop_node = s->top;
	s->top = s->top->prev;
	if (s->top)
		s->top->next = NULL;
	if (!s->top)
		s->bottom = NULL;
	s->nnode--;
	free(pop_node);
	return (ret_val);
}

int	lpop_stack(t_stack *s)
{
	t_node	*pop_node;
	int		ret_val;

	if (s->nnode == 0)
		error_detect();
	ret_val = s->bottom->val;
	pop_node = s->bottom;
	s->bottom = s->bottom->next;
	if (s->bottom)
		s->bottom->prev = NULL;
	if (!s->bottom)
		s->top = NULL;
	s->nnode--;
	free(pop_node);
	return (ret_val);
}
