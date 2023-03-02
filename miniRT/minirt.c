/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:28:37 by dham              #+#    #+#             */
/*   Updated: 2023/03/02 14:24:04 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

int	make_image(t_info *info, t_img *img, const char *rt_file)
{
	int			res;
	t_content	content;

	ft_memset(&content, 0, sizeof(t_content));
	res = parsing(rt_file, &content);
	if (res != SUCCESS)
		return (res);
	res = draw_img(info, img, &content);
	clear_list(&content);
	if (res != SUCCESS)
		return (res);
	return (res);
}

int	draw_img(t_info *info, t_img *img, t_content *content)
{
	int		x;
	int		y;
	int		color;
	t_color	*buf[WIDTH];

	bright_normalize(content);
	camera_set(content);
	// obj nomal vec nomalize
	x = -1;
	while (++x < WIDTH)
	{
		buf[x] = malloc(sizeof(t_color) * HEIGHT);
		if (!buf[x])
		{
			y = -1;
			while (++y < x)
				free(buf[y]);
			return (FATAL_ERROR);
		}
	}
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
			buf[x][y] = ray_calculate(x, y, content);
	}
	buf_nomalize(buf);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
			my_mlx_pixel_put(img, x, y, color_to_int(&buf[x][y]));
	}
	x = -1;
	while (++x < WIDTH)
		free(buf[x]);
	return (SUCCESS);
}

t_color	ray_calculate(int x, int y, t_content *content)
{
	t_ray	ray;
	float	t;
	float	min_t;
	t_obj	*obj;
	t_obj	*hit_obj;

	make_ray(x, y, &ray, content);
	hit_obj = NULL;
	min_t = -1;
	obj = content->obj_list.next;
	while (obj)
	{
		t = cam_obj_distance(&ray, obj);
		if (t > 0 && (eq_f(min_t, -1) || min_t > t))
		{
			min_t = t;
			hit_obj = obj;
		}
		obj = obj->next;
	}
	if (min_t < 0)
		return ((t_color){20, 20, 20});
	else
		return (color_cal(&ray, min_t, content, hit_obj));
}

float	cam_obj_distance(t_ray *ray, t_obj *obj)
{
	if (obj->shape == SPHERE)
		return (sphere_distance(ray, obj));
	else if (obj->shape == PLANE)
		return (plane_distance(ray, obj));
	else if (obj->shape == CYLINDER)
		return (cylinder_distance(ray, obj));
	else
		return (cone_distance(ray, obj));
}

t_color	color_cal(t_ray *ray, float min_t, t_content *content, t_obj *hit_obj)
{
	t_color	color;

	if (hit_obj->shape == SPHERE)
		color = sphere_color(ray, min_t, content, hit_obj);
	else if (hit_obj->shape == PLANE)
		color = plane_color(ray, min_t, content, hit_obj);
	else if (hit_obj->shape == CYLINDER)
		color = cylinder_color(ray, min_t, content, hit_obj);
	else
		color = cone_color(ray, min_t, content, hit_obj);
	return (color);
}