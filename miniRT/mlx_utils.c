/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:22:17 by dham              #+#    #+#             */
/*   Updated: 2023/02/28 18:41:31 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>

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
	content->ambient.bright /= total_b;
	light = content->light_list.next;
	while (light)
	{
		light->bright /= total_b;
		light = light->next;
	}
}

void	make_ray(int x, int y, t_ray *ray, t_content *content)
{
	float	e;
	t_vec	temp;

	e = (2 * tan(content->camera.fov / 2.)) / WIDTH;
	x -= WIDTH / 2;
	y = -y + (HEIGHT / 2);
	ray->start = content->camera.loc;
	ray->dir = content->camera.dir;
	temp = vec_multi(&(content->camera.hor), e * x);
	ray->dir = vec_plus(&ray->dir, &temp);
	temp = vec_multi(&(content->camera.ver), e * y);
	ray->dir = vec_plus(&ray->dir, &temp);
	vector_normalize(&(ray->dir));
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

int	clear_list(t_content *content)
{
	;
}

