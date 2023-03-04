/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:23:50 by dham              #+#    #+#             */
/*   Updated: 2023/03/04 14:41:26 by dham             ###   ########.fr       */
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
	if (vec_inner(&ray->dir, &ce) > 0 || \
		(vec_inner(&ray->dir, &ce) < 0 && square_f(vec_inner(&ray->dir, &ce)) < det))
		return (-vec_inner(&ray->dir, &ce) + sqrtf(det));
	return (-vec_inner(&ray->dir, &ce) - sqrtf(det));
}

t_vec	sphere_nomal_v(t_vec *hit_p, t_obj *hit_obj)
{
	t_vec	ret_v;

	ret_v = vec_minus(hit_p, &hit_obj->loc);
	vector_normalize(&ret_v);
	return (ret_v);
}
