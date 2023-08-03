/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bright_ctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:39:15 by dham              #+#    #+#             */
/*   Updated: 2023/04/01 17:53:36 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void	bright_normalize(t_content *content)
{
	float	total_b;
	t_light	*light;

	total_b = 0;
	total_b += content->ambient.bright;
	light = content->light_list.next;
	while (light)
	{
		total_b += light->bright;
		light = light->next;
	}
	bright_set(&content->ambient.color, content->ambient.bright);
	light = content->light_list.next;
	while (light)
	{
		bright_set(&light->color, light->bright);
		light = light->next;
	}
}

int	bright_color(t_color *color)
{
	int	br;

	br = 0;
	if (color->r > br)
		br = color->r;
	if (color->g > br)
		br = color->g;
	if (color->b > br)
		br = color->b;
	return (br);
}

void	bright_modi(t_color *color, int max)
{
	float	r;
	int		bright;
	float	w;

	bright = bright_color(color);
	if (bright <= 200)
		return ;
	r = (float)-(((bright - 200) - (max - 200)) \
				* ((bright - 200) - (max - 200))) \
				/ ((max - 200) * (max - 200) / 55) + 55;
	w = (200 + r) / bright;
	bright_set(color, w);
}

void	bright_set(t_color *color, float bright)
{
	if (color->r)
	{
		color->r = round(color->r * bright);
		if (color->r == 0)
			color->r = 1;
	}
	if (color->g)
	{
		color->g = round(color->g * bright);
		if (color->g == 0)
			color->g = 1;
	}
	if (color->b)
	{
		color->b = round(color->b * bright);
		if (color->b == 0)
			color->b = 1;
	}
}
