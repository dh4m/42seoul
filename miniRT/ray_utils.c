/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:48:44 by dham              #+#    #+#             */
/*   Updated: 2023/03/19 16:49:50 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void	make_ray(int x, int y, t_ray *ray, t_content *content)
{
	float				e;
	t_vec				temp;
	static const double	degree = M_PI / 180;

	e = (2 * tan(content->camera.fov * degree / 2.)) / ((WIDTH * 2) - 1);
	x -= WIDTH;
	y = -y + (HEIGHT);
	ray->start = content->camera.loc;
	ray->dir = content->camera.dir;
	temp = vec_multi(&(content->camera.hor), e * x);
	ray->dir = vec_plus(&ray->dir, &temp);
	temp = vec_multi(&(content->camera.ver), e * y);
	ray->dir = vec_plus(&ray->dir, &temp);
	vector_normalize(&(ray->dir));
	ray->reflect = 0;
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
	while (obj)
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

float	attenuation(t_light *light, t_hitpoint *hitinfo)
{
	float	d;
	t_vec	light_to_obj;

	light_to_obj = vec_minus(&light->loc, &hitinfo->hit_p);
	d = vector_size(&light_to_obj);
	return (1 / d);
}
