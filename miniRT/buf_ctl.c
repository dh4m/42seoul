/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_ctl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:36:58 by dham              #+#    #+#             */
/*   Updated: 2023/03/19 16:37:53 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void	buf_nomalize(t_color *buf[])
{
	int		y;
	int		x;
	int		max;
	int		bright;

	x = -1;
	max = 255;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			bright = bright_color(&buf[x][y]);
			if (bright > max)
				max = bright;
		}
	}
	x = -1;
	while (++x < WIDTH && max > 255)
	{
		y = -1;
		while (++y < HEIGHT)
			bright_modi(&buf[x][y], max);
	}
}

int	buf_init(t_color *buf[])
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		buf[x] = malloc(sizeof(t_color) * (HEIGHT));
		if (!buf[x])
		{
			y = -1;
			while (++y < x)
				free(buf[y]);
			return (FATAL_ERROR);
		}
	}
	return (SUCCESS);
}
