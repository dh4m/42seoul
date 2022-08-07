/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:35:07 by dham              #+#    #+#             */
/*   Updated: 2022/07/27 15:48:04 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->nnode == 2)
		sort2(a);
	else if (a->nnode == 3)
		sort3(a, b);
	else if (a->nnode == 5)
		sort5(a, b);
	else
		sandclock(a, b);
}
