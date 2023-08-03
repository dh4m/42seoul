/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:28:37 by dham              #+#    #+#             */
/*   Updated: 2023/03/19 16:21:16 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>
#include <pthread.h>

int	make_image(t_img *img, const char *rt_file)
{
	int			res;
	t_content	content;

	ft_memset(&content, 0, sizeof(t_content));
	res = parsing(rt_file, &content);
	if (res != SUCCESS)
		return (error_msg(res, &content));
	res = draw_img(img, &content);
	if (res != SUCCESS)
		return (error_msg(res, &content));
	clear_list(&content);
	return (res);
}

int	draw_img(t_img *img, t_content *content)
{
	int		x;
	int		y;
	t_color	*buf[WIDTH];

	bright_normalize(content);
	camera_set(content);
	obj_vec_nomalize(content);
	if (buf_init(buf) == FATAL_ERROR)
		return (FATAL_ERROR);
	buf_drawing(buf, content);
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
		return ((t_color){0, 0, 0});
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
