/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:57:37 by dham              #+#    #+#             */
/*   Updated: 2023/03/05 21:51:52 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

t_color	sphere_mapped_color(t_obj *obj, t_vec *hit_p)
{
	int			checker_num;
	const t_vec	uv = uv_calculate(hit_p, obj);
	
	if (obj->checker)
	{
		checker_num = obj->diameter * 4;
		if ((int)(roundf(uv.x * checker_num) + roundf(uv.y * checker_num)) % 2)
			return (obj->color);
		else
			return (color_reversal(&obj->color));
	}
	return (obj->color);
}

t_color	plane_mapped_color(t_obj *obj, t_vec *hit_p)
{
	return (obj->color);
}

t_color	cylinder_mapped_color(t_obj *obj, t_vec *hit_p)
{
	return (obj->color);
}

t_color	cone_mapped_color(t_obj *obj, t_vec *hit_p)
{
	return (obj->color);
}

t_color	mapped_color(t_obj *obj, t_vec *hit_p)
{
	if (obj->shape == SPHERE)
		return (sphere_mapped_color(obj, hit_p));
	else if (obj->shape == PLANE)
		return (plane_mapped_color(obj, hit_p));
	else if (obj->shape == CYLINDER)
		return (cylinder_mapped_color(obj, hit_p));
	else
		return (cone_mapped_color(obj, hit_p));
}
