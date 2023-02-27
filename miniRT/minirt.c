/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:28:37 by dham              #+#    #+#             */
/*   Updated: 2023/02/27 18:49:42 by dham             ###   ########.fr       */
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
	int	x;
	int	y;
	int	color;

	bright_normalize(content);
	camera_set(content);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			color = ray_calculate(x, y, content);
			my_mlx_pixel_put(img, x, y, color);
		}
	}
	return (SUCCESS);
}

int	ray_calculate(int x, int y, t_content *content)
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
		if (t > 0 && (min_t == -1 || min_t > t))
		{
			min_t = t;
			hit_obj = obj;//////
		}
		obj = obj->next;
	}
	return (0x00ffffff);
}

float	cam_obj_distance(t_ray *ray, t_obj *obj)
{

}