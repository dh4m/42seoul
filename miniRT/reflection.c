/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:44:23 by dham              #+#    #+#             */
/*   Updated: 2023/03/01 19:15:42 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static void	make_reflect_ray(t_ray *ray, t_ray *ray_origin, t_hitpoint *hitinfo)
{
	t_vec	temp;

	temp = vec_multi(&hitinfo->nomal_v, 0.1);
	ray->start = vec_plus(&hitinfo->hit_p, &temp);
	temp = vec_multi(&hitinfo->nomal_v, 2 * vec_inner(&hitinfo->nomal_v, &ray_origin->dir));
	ray->dir = vec_minus(&ray_origin->dir, &temp);
	vector_normalize(&(ray->dir));
	ray->reflect = ray_origin->reflect + 1;
}

t_color	reflect_value(t_hitpoint *hitinfo, t_content *content, t_ray *ray_origin)
{
	t_ray	ray;
	float	t;
	float	min_t;
	t_obj	*obj;
	t_obj	*hit_obj;

	make_reflect_ray(&ray, ray_origin, hitinfo);
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
	return (color_cal(&ray, min_t, content, hit_obj));
}