/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:44:23 by dham              #+#    #+#             */
/*   Updated: 2023/03/02 00:26:58 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static void	make_reflect_ray(t_ray *ray, t_vec *ray_origin, t_hitpoint *hitinfo, int ref_num)
{
	t_vec	temp;

	temp = vec_multi(&hitinfo->nomal_v, 0.001);
	ray->start = vec_plus(&hitinfo->hit_p, &temp);
	temp = vec_multi(&hitinfo->nomal_v, 2 * vec_inner(&hitinfo->nomal_v, ray_origin));
	ray->dir = vec_minus(ray_origin, &temp);
	vector_normalize(&(ray->dir));
	ray->reflect = ref_num + 1;
}

t_color	reflect_value(t_hitpoint *hitinfo, t_content *content, t_ray *ray_origin)
{
	t_ray	ray;
	float	t;
	float	min_t;
	t_obj	*obj;
	t_obj	*hit_obj;

	make_reflect_ray(&ray, &ray_origin->dir, hitinfo, ray_origin->reflect);
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

static t_color	sparkle_value(t_hitpoint *hitinfo, t_content *content, t_obj *hit_obj)
{
	t_ray	ray;////
	t_color	ret_c;
	t_color	temp_c;
	t_vec	temp_v;
	t_light	*light;

	ret_c.r = 0;
	ret_c.g = 0;
	ret_c.b = 0;
	light = content->light_list.next;
	while(light)
	{
		if (light_hit(light, &hitinfo->hit_p, content, hit_obj))
		{
			temp_v = vec_minus(&hitinfo->hit_p, &light->loc);
			vector_normalize(&temp_v);
			make_reflect_ray(&ray, &temp_v, hitinfo, 0);
			temp_c = light->color;
			temp_v = vec_minus(&content->camera.loc, &hitinfo->hit_p);
			vector_normalize(&temp_v);
			if (vec_inner(&ray.dir, &temp_v) > 0)
			{
				bright_set(&temp_c, powf(vec_inner(&ray.dir, &temp_v), hit_obj->sparkle));
				ret_c = color_combine(&ret_c, &temp_c);
			}
		}
		light = light->next;
	}
	return (ret_c);
}

t_color	specular_value(t_hitpoint *hitinfo, t_content *content, t_ray *ray_origin, t_obj *obj)
{
	t_color	ret_c;
	t_color	sparkle;

	ret_c = reflect_value(hitinfo, content, ray_origin);
	ret_c = reflex_color(&ret_c, &obj->color);
	sparkle = sparkle_value(hitinfo, content, obj);
	ret_c = color_combine(&ret_c, &sparkle);
	
	return (ret_c);
}