/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:12:28 by dham              #+#    #+#             */
/*   Updated: 2022/07/28 11:31:39 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

int		*arr_sort(t_stack *a);

void	ko_print(void);
void	ok_print(void);

void	read_cmd(t_stack *a, t_stack *b, int *ans);
void	operate_cmd(t_stack *a, t_stack *b, char *cmd);

#endif