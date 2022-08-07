/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:20:28 by dham              #+#    #+#             */
/*   Updated: 2022/07/27 20:58:35 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		nnode;
}	t_stack;

void	init_stack(t_stack *a, t_stack *b);
void	push_stack(t_stack *s, int num);
void	lpush_stack(t_stack *s, int num);
int		pop_stack(t_stack *s);
int		lpop_stack(t_stack *s);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	arg_load(t_stack *a, int argc, char *argv[]);
void	stack_input(t_stack *a, char **argv);
void	avail_arg(char *str);
void	overflow_check(int num, char *str);
void	free_split(char **list);

void	error_detect(void);
void	free_stack(t_stack *s);
int		is_sorted(t_stack *s, int *arr);
void	dup_check(int *arr, int num);

void	sort_stack(t_stack *a, t_stack *b);

void	sort2(t_stack *a);

void	sort3_only(t_stack *a, int case_num);
void	sort3_top(t_stack *a, t_stack *b, int case_num);
int		case_check3(t_stack *s);
void	sort3(t_stack *a, t_stack *b);

void	sort5(t_stack *a, t_stack *b);

int		*arr_sort(t_stack *a);

void	preprocess(t_stack *a, int *arr);

void	sandclock(t_stack *a, t_stack *b);
void	transfer_b(t_stack *a, t_stack *b, int gap);
void	transfer_a(t_stack *a, t_stack *b, int max);
void	count_pad(t_stack *b, int need);
void	show_move(t_stack *b, int count);
void	shift_num(t_stack *a, t_stack *b, int *need);

#endif