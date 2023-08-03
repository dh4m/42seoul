/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ctl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:41:12 by dham              #+#    #+#             */
/*   Updated: 2023/03/19 16:41:55 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

t_color	reflex_color(t_color *light, t_color *obj)
{
	t_color	ret_c;

	ret_c.r = round(obj->r * (light->r / 255.));
	ret_c.g = round(obj->g * (light->g / 255.));
	ret_c.b = round(obj->b * (light->b / 255.));
	return (ret_c);
}

t_color	color_combine(t_color *a, t_color *b)
{
	t_color	ret_c;

	ret_c.r = a->r + b->r;
	ret_c.g = a->g + b->g;
	ret_c.b = a->b + b->b;
	return (ret_c);
}

int	color_to_int(t_color *color)
{
	int	ret_i;

	ret_i = 0;
	ret_i += (color->r << 16);
	ret_i += (color->g << 8);
	ret_i += color->b;
	return (ret_i);
}

t_color	int_to_color(int code)
{
	t_color	ret_c;

	ret_c.r = (code >> 16) & 0xff;
	ret_c.g = (code >> 8) & 0xff;
	ret_c.b = code & 0xff;
	return (ret_c);
}

t_color	color_reversal(t_color *origin)
{
	t_color	ret_c;
	int		max;

	max = 255;
	if (origin->r > max)
		max = origin->r;
	if (origin->g > max)
		max = origin->g;
	if (origin->b > max)
		max = origin->b;
	ret_c.r = max - origin->r;
	ret_c.g = max - origin->g;
	ret_c.b = max - origin->b;
	return (ret_c);
}
