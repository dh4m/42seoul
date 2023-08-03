/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:22:17 by dham              #+#    #+#             */
/*   Updated: 2023/03/19 16:51:42 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	win_destroy(void *param)
{
	(void) param;
	exit(0);
}

void	camera_set(t_content *content)
{
	vector_normalize(&(content->camera.dir));
	content->camera.hor.z = 0;
	if (eq_f(content->camera.dir.x, 0) && eq_f(content->camera.dir.y, 0))
	{	
		content->camera.hor.x = 0;
		content->camera.hor.y = 1;
	}
	else
	{
		content->camera.hor.x = content->camera.dir.y;
		content->camera.hor.y = -content->camera.dir.x;
		vector_normalize(&(content->camera.hor));
	}
	content->camera.ver = vec_cross(&content->camera.hor, \
										&content->camera.dir);
}

void	obj_vec_nomalize(t_content *contect)
{
	t_obj	*obj;

	obj = contect->obj_list.next;
	while (obj)
	{
		if (obj->shape != SPHERE)
			vector_normalize(&obj->nomal_v);
		obj = obj->next;
	}
}
