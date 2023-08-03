/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:38:29 by dham              #+#    #+#             */
/*   Updated: 2023/03/19 16:05:03 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

t_vec	int_to_bump_v(int bump_code)
{
	t_color	temp;
	t_vec	bump_v;

	temp = int_to_color(bump_code);
	bump_v.x = (temp.r / 255.) * 2 - 1;
	bump_v.y = (temp.g / 255.) * 2 - 1;
	bump_v.z = (temp.b / 255.) * 2 - 1;
	vector_normalize(&bump_v);
	return (bump_v);
}

t_vec	bump_nomal_v_cal(t_vec *nomal_v, int bump_code)
{
	t_vec		x;
	t_vec		y;
	t_vec		defalt_x;
	const t_vec	bump_v = int_to_bump_v(bump_code);
	t_vec		ret_v;

	defalt_x = (t_vec){0, 0, 1};
	if (eq_f(nomal_v->z, 1))
		defalt_x = (t_vec){1, 0, 0};
	y = vec_cross(nomal_v, &defalt_x);
	x = vec_cross(&y, nomal_v);
	ret_v.x = x.x * bump_v.x + y.x * bump_v.y + nomal_v->x * bump_v.z;
	ret_v.y = x.y * bump_v.x + y.y * bump_v.y + nomal_v->y * bump_v.z;
	ret_v.z = x.z * bump_v.x + y.z * bump_v.y + nomal_v->z * bump_v.z;
	return (ret_v);
}

t_vec	nomal_v_cal(t_hitpoint *hitinfo, t_obj *hit_obj, t_vec *ray_dir)
{
	t_vec	ret_v;
	int		bump_val;

	if (hit_obj->shape == SPHERE)
		ret_v = sphere_nomal_v(&hitinfo->hit_p, hit_obj);
	else if (hit_obj->shape == PLANE)
		ret_v = plane_nomal_v(hit_obj);
	else if (hit_obj->shape == CYLINDER)
		ret_v = cylinder_nomal_v(&hitinfo->hit_p, hit_obj);
	else
		ret_v = cone_nomal_v(&hitinfo->hit_p, hit_obj);
	if (vec_inner(&ret_v, ray_dir) > 0)
		ret_v = vec_multi(&ret_v, -1);
	if (hit_obj->bump)
	{
		bump_val = hit_obj->bump->data \
				[(int)roundf(hitinfo->uv.y * (hit_obj->bump->height - 1))] \
				[(int)roundf(hitinfo->uv.x * (hit_obj->bump->width - 1))];
		return (bump_nomal_v_cal(&ret_v, bump_val));
	}
	return (ret_v);
}

t_color	mapped_color(t_hitpoint *hitinfo, t_obj *obj)
{
	float		checker_num;
	const t_vec	uv = hitinfo->uv;
	int			color_code;

	if (obj->checker)
	{
		checker_num = obj->diameter * 13;
		if (obj->shape == PLANE)
			checker_num = 1;
		if ((int)(roundf(uv.x * checker_num) + roundf(uv.y * checker_num)) % 2)
			return (obj->color);
		else
			return (color_reversal(&obj->color));
	}
	else if (obj->texture)
	{
		color_code = obj->texture->data \
					[(int)roundf(uv.y * (obj->texture->height - 1))] \
					[(int)roundf(uv.x * (obj->texture->width - 1))];
		return (int_to_color(color_code));
	}
	return (obj->color);
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
	hit_info.uv = uv_calculate(&hit_info.hit_p, hit_obj);
	hit_info.nomal_v = nomal_v_cal(&hit_info, hit_obj, &ray->dir);
	hit_info.point_color = mapped_color(&hit_info, hit_obj);
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
