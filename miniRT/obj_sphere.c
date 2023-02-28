/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:23:50 by dham              #+#    #+#             */
/*   Updated: 2023/02/28 19:53:46 by dham             ###   ########.fr       */
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
		return (-vec_inner(&ray->dir, &ce) - sqrtf(det));
	return (-vec_inner(&ray->dir, &ce) + sqrtf(det));
}

static t_vec	nomal_v_cal(t_vec *hit_p, t_obj *hit_obj)
{
	;
}

int	sphere_color(t_ray *ray, float t, t_content *content, t_obj *hit_obj)
{
	t_color ambi;
	t_color	diffuse;
	t_color	specular;
	t_vec	nomal_v;
	t_vec	hit_p;

	hit_p = vec_multi(&ray->dir, t);
	hit_p = vec_plus(&hit_p, &ray->start);
	nomal_v = nomal_v_cal(&hit_p, hit_obj);
}