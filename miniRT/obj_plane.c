/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:23:53 by dham              #+#    #+#             */
/*   Updated: 2023/03/02 14:56:20 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

float	plane_distance(t_ray *ray, t_obj *obj)
{
	float	t;
	t_vec	ea;
	t_vec	len;

	if (eq_f(vec_inner(&obj->nomal_v, &ray->dir), 0))
		return (-1);
	ea = vec_minus(&obj->loc, &ray->start);
	t = vec_inner(&ea, &obj->nomal_v) / vec_inner(&obj->nomal_v, &ray->dir);
	len = vec_multi(&ray->dir, t);
	len = vec_plus(&len, &ray->start);
	len = vec_minus(&len, &obj->loc);
	if (obj->diameter > 0 && vector_size(&len) > obj->diameter / 2)
		return (-1);
	return (t);
}

static t_vec	nomal_v_cal(t_vec *hit_p, t_obj *hit_obj)
{
	return (hit_obj->nomal_v);
}

static t_color	diffuse_value(t_hitpoint *hitinfo, \
								t_content *content, t_obj *hit_obj)
{
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
			temp_c = reflex_color(&light->color, &hitinfo->point_color);
			temp_v = vec_minus(&light->loc, &hitinfo->hit_p);
			vector_normalize(&temp_v);
			if (vec_inner(&hitinfo->nomal_v, &temp_v) > 0)
			{
				bright_set(&temp_c, vec_inner(&hitinfo->nomal_v, &temp_v) * (1 - hit_obj->reflection));
				ret_c = color_combine(&ret_c, &temp_c);
			}
		}
		light = light->next;
	}
	return (ret_c);
}

t_color	plane_color(t_ray *ray, float t, t_content *content, t_obj *hit_obj)
{
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_color		ret_c;
	t_hitpoint	hit_info;

	hit_info.hit_p = vec_multi(&ray->dir, t);
	hit_info.hit_p = vec_plus(&hit_info.hit_p, &ray->start);
	hit_info.nomal_v = nomal_v_cal(&hit_info.hit_p, hit_obj);
	hit_info.point_color = plane_mapped_color(hit_obj, &hit_info.hit_p);
	ambient = reflex_color(&content->ambient.color, &hit_info.point_color);
	bright_set(&ambient, 1 - hit_obj->reflection);
	diffuse = diffuse_value(&hit_info, content, hit_obj);
	ret_c = color_combine(&ambient, &diffuse);
	if (ray->reflect <= REFL_NUM)
	{
		specular = specular_value(&hit_info, content, ray, hit_obj);
		bright_set(&specular, hit_obj->reflection);
		ret_c = color_combine(&ret_c, &specular);
	}
	if (t > 1)
		bright_set(&ret_c, powf(1 / t, 0.5));
	return (ret_c);
}