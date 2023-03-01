/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:22:17 by dham              #+#    #+#             */
/*   Updated: 2023/03/02 00:21:24 by dham             ###   ########.fr       */
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

void	make_ray(int x, int y, t_ray *ray, t_content *content)
{
	float	e;
	t_vec	temp;
	static const double degree = M_PI / 180;

	e = (2 * tan(content->camera.fov * degree / 2.)) / (WIDTH - 1);
	x -= WIDTH / 2;
	y = -y + (HEIGHT / 2);
	ray->start = content->camera.loc;
	ray->dir = content->camera.dir;
	temp = vec_multi(&(content->camera.hor), e * x);
	ray->dir = vec_plus(&ray->dir, &temp);
	temp = vec_multi(&(content->camera.ver), e * y);
	ray->dir = vec_plus(&ray->dir, &temp);
	vector_normalize(&(ray->dir));
	ray->reflect = 0;
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

void	bright_set(t_color *color, float bright)
{
	color->r = round(color->r * bright);
	color->g = round(color->g * bright);
	color->b = round(color->b * bright);
}

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

float	distance_point(t_vec *v1, t_vec *v2)
{
	t_vec	temp;
	
	temp = vec_minus(v2, v1);
	return (vector_size(&temp));
}

int	light_hit(t_light *light, t_vec *hit_p, t_content *content, t_obj *hit_obj)
{
	const float	light_distance = distance_point(&light->loc, hit_p);
	float		obj_distance;
	t_obj		*obj;
	t_ray		ray;

	ray.start = *hit_p;
	ray.dir = vec_minus(&light->loc, hit_p);
	vector_normalize(&ray.dir);
	obj = content->obj_list.next;
	while(obj)
	{
		if (obj != hit_obj)
		{
			obj_distance = cam_obj_distance(&ray, obj);
			if (obj_distance > 0 && obj_distance < light_distance)
				return (0);
		}
		obj = obj->next;
	}
	return (1);
}

void	buf_nomalize(t_color *buf)
{
	int		y;
	int		x;
	int		max = 255;
	float	r;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (buf[x + (y * WIDTH)].r > max)
				max = buf[x + (y * WIDTH)].r;
			if (buf[x + (y * WIDTH)].g > max)
				max = buf[x + (y * WIDTH)].g;
			if (buf[x + (y * WIDTH)].b > max)
				max = buf[x + (y * WIDTH)].b;
		}
	}
	if (max == 255)
		return ;
	r = 255. / max;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			bright_set(&buf[x + (y * WIDTH)], r);
	}
}