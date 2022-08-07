/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:09:24 by dham              #+#    #+#             */
/*   Updated: 2022/07/28 11:50:07 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "checker_bonus.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		*sorted_num;

	init_stack(&a, &b);
	arg_load(&a, argc - 1, &argv[1]);
	if (argc < 2)
		return (0);
	sorted_num = arr_sort(&a);
	dup_check(sorted_num, a.nnode);
	read_cmd(&a, &b, sorted_num);
	free_stack(&a);
	free_stack(&b);
	free(sorted_num);
	return (0);
}

void	read_cmd(t_stack *a, t_stack *b, int *ans)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		operate_cmd(a, b, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (is_sorted(a, ans) && b->nnode == 0)
		ok_print();
	else
		ko_print();
}

void	operate_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_strncmp(cmd, "sa\n", ft_strlen(cmd)) == 0)
		sa(a);
	else if (ft_strncmp(cmd, "sb\n", ft_strlen(cmd)) == 0)
		sb(b);
	else if (ft_strncmp(cmd, "ss\n", ft_strlen(cmd)) == 0)
		ss(a, b);
	else if (ft_strncmp(cmd, "pa\n", ft_strlen(cmd)) == 0)
		pa(a, b);
	else if (ft_strncmp(cmd, "pb\n", ft_strlen(cmd)) == 0)
		pb(a, b);
	else if (ft_strncmp(cmd, "ra\n", ft_strlen(cmd)) == 0)
		ra(a);
	else if (ft_strncmp(cmd, "rb\n", ft_strlen(cmd)) == 0)
		rb(b);
	else if (ft_strncmp(cmd, "rr\n", ft_strlen(cmd)) == 0)
		rr(a, b);
	else if (ft_strncmp(cmd, "rra\n", ft_strlen(cmd)) == 0)
		rra(a);
	else if (ft_strncmp(cmd, "rrb\n", ft_strlen(cmd)) == 0)
		rrb(b);
	else if (ft_strncmp(cmd, "rrr\n", ft_strlen(cmd)) == 0)
		rrr(a, b);
	else
		error_detect();
}
