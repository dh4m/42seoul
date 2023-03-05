/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:58:17 by dham              #+#    #+#             */
/*   Updated: 2023/03/05 21:53:36 by dham             ###   ########.fr       */
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
	uv.x /= 2 * M_PI;///////
	uv.y = acosf(cp.z);
	uv.y /= M_PI;
	return (uv);
}

t_vec	uv_plane(t_vec *hit_p, t_obj *obj)
{
	;
}

t_vec	uv_cylinder(t_vec *hit_p, t_obj *obj)
{
	;
}

t_vec	uv_cone(t_vec *hit_p, t_obj *obj)
{
	;
}

t_vec	uv_calculate(t_vec *hit_p, t_obj *obj)
{
	if (obj->shape == SPHERE)
		return (uv_sphere(hit_p, obj));
	else if (obj->shape == PLANE)
		return (uv_plane(hit_p, obj));
	else if (obj->shape == CYLINDER)
		return (uv_cylinder(hit_p, obj));
	else
		return (uv_cone(hit_p, obj));
}