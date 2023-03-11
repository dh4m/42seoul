/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:58:17 by dham              #+#    #+#             */
/*   Updated: 2023/03/11 16:07:14 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

t_vec	uv_sphere(t_vec *hit_p, t_obj *obj)
{
	t_vec	uv;
	t_vec	cp;

	cp = vec_minus(hit_p, &obj->loc);
	vector_normalize(&cp);
	if (cp.y >= 0)
		uv.x = atan2f(cp.y, cp.x);
	else
		uv.x = atan2f(cp.y, cp.x) + 2 * M_PI;
	uv.x /= 2 * M_PI;
	uv.y = acosf(cp.z);
	uv.y /= M_PI;
	return (uv);
}

t_vec	uv_plane(t_vec *hit_p, t_obj *obj)
{
	t_vec	uv;
	t_vec	x;
	t_vec	y;
	t_vec	defalt_x;

	defalt_x = (t_vec){1, 0, 0};
	if (eq_f(obj->nomal_v.x, 1))
		defalt_x = (t_vec){0, 0, 1};
	y = vec_cross(&obj->nomal_v, &defalt_x);
	x = vec_cross(&y, &obj->nomal_v);
	uv.x = fmodf(vec_inner(hit_p, &x), 1);
	if(uv.x < 0)
		uv.x += 1;
	uv.y = fmodf(vec_inner(hit_p, &y), 1);
	if(uv.y < 0)
		uv.y += 1;
	return (uv);
}

t_vec	uv_cylinder_cone(t_vec *hit_p, t_obj *obj)
{
	t_vec	uv;
	t_vec	x;
	t_vec	y;
	t_vec	defalt_x;
	t_vec	cp;

	defalt_x = (t_vec){1, 0, 0};
	if (eq_f(obj->nomal_v.x, -1))
		defalt_x = (t_vec){0, 0, 1};
	cp = vec_minus(hit_p, &obj->loc);
	y = vec_cross(&obj->nomal_v, &defalt_x);
	x = vec_cross(&y, &obj->nomal_v);
	uv.x = vec_inner(&cp, &x);
	uv.y = vec_inner(&cp, &y);
	if (uv.y >= 0)
		uv.x = atan2f(uv.y, uv.x);
	else
		uv.x = atan2f(uv.y, uv.x) + 2 * M_PI;
	uv.x /= 2 * M_PI;
	uv.y = fmodf(obj->height - vec_inner(&cp, &obj->nomal_v), 1);
	return (uv);
}

t_vec	uv_calculate(t_vec *hit_p, t_obj *obj)
{
	if (obj->shape == SPHERE)
		return (uv_sphere(hit_p, obj));
	else if (obj->shape == PLANE)
		return (uv_plane(hit_p, obj));
	else
		return (uv_cylinder_cone(hit_p, obj));
}