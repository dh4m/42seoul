/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:20:17 by dham              #+#    #+#             */
/*   Updated: 2022/07/27 19:20:01 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		*sorted_num;

	init_stack(&a, &b);
	arg_load(&a, argc - 1, &argv[1]);
	if (a.nnode < 2)
		return (0);
	sorted_num = arr_sort(&a);
	dup_check(sorted_num, a.nnode);
	if (!is_sorted(&a, sorted_num))
	{
		preprocess(&a, sorted_num);
		sort_stack(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	free(sorted_num);
	return (0);
}
