/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:38:29 by dham              #+#    #+#             */
/*   Updated: 2023/03/05 13:25:27 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

t_vec	nomal_v_cal(t_vec *hit_p, t_obj *hit_obj, t_vec *ray_dir)
{
	t_vec	ret_v;

	if (hit_obj->shape == SPHERE)
		ret_v = sphere_nomal_v(hit_p, hit_obj);
	else if (hit_obj->shape == PLANE)
		ret_v = plane_nomal_v(hit_p, hit_obj);
	else if (hit_obj->shape == CYLINDER)
		ret_v = cylinder_nomal_v(hit_p, hit_obj);
	else
		ret_v = cone_nomal_v(hit_p, hit_obj);
	if (vec_inner(&ret_v, ray_dir) > 0)
		ret_v = vec_multi(&ret_v, -1);
	return (ret_v);
}

t_color	color_cal(t_ray *ray, float t, t_content *content, t_obj *hit_obj)
{
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_color		ret_c;
	t_hitpoint	hit_info;

	hit_info.hit_p = vec_multi(&ray->dir, t);
	hit_info.hit_p = vec_plus(&hit_info.hit_p, &ray->start);
	hit_info.nomal_v = nomal_v_cal(&hit_info.hit_p, hit_obj, &ray->dir);
	hit_info.point_color = mapped_color(hit_obj, &hit_info.hit_p);
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
	return (ret_c);
}