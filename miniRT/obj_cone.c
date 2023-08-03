/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:23:59 by dham              #+#    #+#             */
/*   Updated: 2023/03/19 13:49:45 by dham             ###   ########.fr       */
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
	if (vec_inner(&cp, &obj->nomal_v) < 0 \
		|| vec_inner(&cp, &obj->nomal_v) > obj->height)
		return (0);
	return (1);
}

static float	t_val_calculate(float det_c[3], float det)
{
	float	t;

	if (det_c[0] < 0)
	{
		t = (-det_c[1] + det) / det_c[0];
		if (t < 0)
			t = (-det_c[1] - det) / det_c[0];
	}
	else
	{
		t = (-det_c[1] - det) / det_c[0];
		if (t < 0)
			t = (-det_c[1] + det) / det_c[0];
	}
	return (t);
}

static float	distance_calculate(float det_c[3], t_ray *ray, t_obj *obj)
{
	float	det;
	float	t;

	det = square_f(det_c[1]) - (det_c[0] * det_c[2]);
	if (det < 0 || eq_f(det_c[0], 0))
		return (-1);
	det = sqrtf(det);
	t = t_val_calculate(det_c, det);
	if (!hit_det(ray, t, obj))
	{
		if (det_c[0] < 0)
			t = (-det_c[1] - det) / det_c[0];
		else
			t = (-det_c[1] + det) / det_c[0];
		if (!hit_det(ray, t, obj))
			return (-1);
	}
	return (t);
}

float	cone_distance(t_ray *ray, t_obj *obj)
{
	const float	cos_square = \
		square_f(obj->height) \
		/ (square_f(obj->height) + square_f(obj->diameter / 2));
	float		det_c[3];
	t_vec		ce;

	ce = vec_minus(&ray->start, &obj->loc);
	det_c[0] = square_f(vec_inner(&ray->dir, &obj->nomal_v)) - cos_square;
	det_c[1] = vec_inner(&ray->dir, &obj->nomal_v) \
				* vec_inner(&ce, &obj->nomal_v) \
				- vec_inner(&ce, &ray->dir) * cos_square;
	det_c[2] = square_f(vec_inner(&ce, &obj->nomal_v)) \
				- vec_square(&ce) * cos_square;
	return (distance_calculate(det_c, ray, obj));
}

t_vec	cone_nomal_v(t_vec *hit_p, t_obj *hit_obj)
{
	t_vec	cp;
	t_vec	temp;
	t_vec	n;

	cp = vec_minus(hit_p, &hit_obj->loc);
	temp = vec_multi(&hit_obj->nomal_v, \
			vec_square(&cp) / vec_inner(&hit_obj->nomal_v, &cp));
	n = vec_minus(&cp, &temp);
	vector_normalize(&n);
	return (n);
}
