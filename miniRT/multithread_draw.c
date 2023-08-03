/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:20:51 by dham              #+#    #+#             */
/*   Updated: 2023/03/19 16:21:14 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

void	*multi_threading_draw(void *args)
{
	int					x;
	int					y;
	t_multithread_arg	*arg;

	arg = args;
	x = arg->max_x - WIDTH / NUM_THREAD - 1;
	while (++x < arg->max_x)
	{
		y = -1;
		while (++y < HEIGHT)
			(arg->buf)[x][y] = antialiasing_color(x, y, arg->content);
	}
	return (NULL);
}

void	buf_drawing(t_color *buf[], t_content *content)
{
	t_multithread_arg	arg[NUM_THREAD];
	int					i;

	i = -1;
	while (++i < NUM_THREAD)
	{
		arg[i].buf = buf;
		arg[i].content = content;
		arg[i].max_x = WIDTH / NUM_THREAD * (i + 1);
		pthread_create(&arg[i].tid, NULL, multi_threading_draw, &arg[i]);
	}
	i = -1;
	while (++i < NUM_THREAD)
	{
		pthread_join(arg[i].tid, NULL);
	}
}
