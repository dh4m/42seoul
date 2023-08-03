/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:19:59 by dham              #+#    #+#             */
/*   Updated: 2023/03/19 16:20:13 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

t_color	take_average(t_color buf[][2])
{
	t_color	average;

	average.r = 0;
	average.g = 0;
	average.b = 0;
	average = color_combine(&average, &buf[0][0]);
	average = color_combine(&average, &buf[1][0]);
	average = color_combine(&average, &buf[0][1]);
	average = color_combine(&average, &buf[1][1]);
	bright_set(&average, 0.25);
	return (average);
}

t_color	antialiasing_color(int x, int y, t_content *content)
{
	t_color	average;
	t_color	around[2][2];

	around[0][0] = ray_calculate(x * 2, y * 2, content);
	around[0][1] = ray_calculate(x * 2 + 1, y * 2, content);
	around[1][0] = ray_calculate(x * 2, y * 2 + 1, content);
	around[1][1] = ray_calculate(x * 2 + 1, y * 2 + 1, content);
	average = take_average(around);
	return (average);
}
