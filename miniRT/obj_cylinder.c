/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:23:41 by dham              #+#    #+#             */
/*   Updated: 2023/03/02 16:33:21 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

static int	hit_det(t_ray *ray, float t, t_obj *obj)
{
	t_vec	cp;

	cp = vec_multi(&ray->dir, t);
	cp = vec_plus(&cp, &ray->start);
	cp = vec_minus(&cp, &obj->loc);
	if (vec_inner(&cp, &obj->nomal_v) < 0 || vec_inner(&cp, &obj->nomal_v) > obj->height)
		return (0);
	return (1);
}

float	cylinder_distance(t_ray *ray, t_obj *obj)
{
	float	det;
	float	det_c[3];
	t_vec	cp;
	t_vec	ce;
	float	t;

	ce = vec_minus(&ray->start, &obj->loc);
	det_c[0] = square_f(vec_inner(&ray->dir, &obj->nomal_v)) - 1;
	det_c[1] = vec_inner(&ray->dir, &obj->nomal_v) * vec_inner(&ce, &obj->nomal_v) \
		- vec_inner(&ce, &ray->dir);
	det_c[2] = square_f(obj->diameter / 2) - vec_square(&ce) + square_f(vec_inner(&ce, &obj->nomal_v));
	det = square_f(det_c[1]) - (det_c[0] * det_c[2]);
	if (det < 0 || eq_f(det_c[0], 0))
		return (-1);
	t = (-det_c[1] + sqrtf(det)) / det_c[0];
	if (t < 0)
		t = (-det_c[1] - sqrtf(det)) / det_c[0];
	if (!hit_det(ray, t, obj))
	{
		if (t == (-det_c[1] - sqrtf(det)) / det_c[0])
			return (-1);
		t = (-det_c[1] - sqrtf(det)) / det_c[0];
		if (!hit_det(ray, t, obj))
			return (-1);
	}
	return (t);
}

static t_vec	nomal_v_cal(t_vec *hit_p, t_obj *hit_obj)
{
	t_vec	cp;
	t_vec	temp;
	t_vec	n;

	cp = vec_minus(hit_p, &hit_obj->loc);
	temp = vec_multi(&hit_obj->nomal_v, vec_inner(&hit_obj->nomal_v, &cp));
	n = vec_minus(&cp, &temp);
	vector_normalize(&n);
	return (n);
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

t_color	cylinder_color(t_ray *ray, float t, t_content *content, t_obj *hit_obj)
{
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_color		ret_c;
	t_hitpoint	hit_info;

	hit_info.hit_p = vec_multi(&ray->dir, t);
	hit_info.hit_p = vec_plus(&hit_info.hit_p, &ray->start);
	hit_info.nomal_v = nomal_v_cal(&hit_info.hit_p, hit_obj);
	hit_info.point_color = sphere_mapped_color(hit_obj, &hit_info.hit_p);
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