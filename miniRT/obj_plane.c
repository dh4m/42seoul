/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:23:53 by dham              #+#    #+#             */
/*   Updated: 2023/03/02 00:19:28 by dham             ###   ########.fr       */
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

t_color	plane_color(t_ray *ray, float t, t_content *content, t_obj *hit_obj)
{
	return ((t_color){255, 255, 255});
}