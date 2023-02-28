/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:23:50 by dham              #+#    #+#             */
/*   Updated: 2023/03/01 04:01:37 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

float	sphere_distance(t_ray *ray, t_obj *obj)
{
	float	det;
	t_vec	ce;

	ce = vec_minus(&ray->start, &obj->loc);
	det = square_f(vec_inner(&ray->dir, &ce)) \
			- vec_square(&ce) + powf(obj->diameter * 0.5, 2);
	if (det < 0)
		return (-1);
	if (vec_inner(&ray->dir, &ce) < 0 \
		&& square_f(vec_inner(&ray->dir, &ce)) < det)
		return (-vec_inner(&ray->dir, &ce) + sqrtf(det));
	return (-vec_inner(&ray->dir, &ce) - sqrtf(det));
}

static t_vec	nomal_v_cal(t_vec *hit_p, t_obj *hit_obj)
{
	t_vec	ret_v;

	ret_v = vec_minus(hit_p, &hit_obj->loc);
	vector_normalize(&ret_v);
	return (ret_v);
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
				bright_set(&temp_c, vec_inner(&hitinfo->nomal_v, &temp_v));
				ret_c = color_combine(&ret_c, &temp_c);
			}
		}
		light = light->next;
	}
	return (ret_c);
}

t_color	sphere_color(t_ray *ray, float t, t_content *content, t_obj *hit_obj)
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_hitpoint	hit_info;

	hit_info.hit_p = vec_multi(&ray->dir, t);
	hit_info.hit_p = vec_plus(&hit_info.hit_p, &ray->start);
	hit_info.nomal_v = nomal_v_cal(&hit_info.hit_p, hit_obj);
	hit_info.point_color = sphere_mapped_color(hit_obj, &hit_info.hit_p);
	ambient = reflex_color(&content->ambient.color, &hit_info.point_color);
	diffuse = diffuse_value(&hit_info, content, hit_obj);
	//specular 구해야 함
	//specular 적용해야 함
	return (color_combine(&ambient, &diffuse));
}