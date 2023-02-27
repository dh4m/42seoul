/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:30:38 by dham              #+#    #+#             */
/*   Updated: 2023/02/27 18:08:45 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>

t_vec	vec_multi(t_vec *vec, float f)
{
	t_vec	ret;

	ret.x = vec->x * f;
	ret.y = vec->y * f;
	ret.z = vec->z * f;
	return (ret);
}

float	vec_inner(const t_vec *vec1, const t_vec *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

t_vec	vec_cross(const t_vec *vec1, const t_vec *vec2)
{
	t_vec	ret;

	ret.x = vec1->y * vec2->z - vec1->z * vec2->y;
	ret.y = -(vec1->x * vec2->z - vec1->z * vec2->x);
	ret.z = vec1->x * vec2->y - vec1->y * vec2->x;
	return (ret);
}

t_vec	vec_plus(const t_vec *vec1, const t_vec *vec2)
{
	t_vec	ret;

	ret.x = vec1->x + vec2->x;
	ret.y = vec1->y + vec2->y;
	ret.z = vec1->z + vec2->z;
	return (ret);
}

t_vec	vec_minus(const t_vec *vec1, const t_vec *vec2)
{
	t_vec	ret;

	ret.x = vec1->x - vec2->x;
	ret.y = vec1->y - vec2->y;
	ret.z = vec1->z - vec2->z;
	return (ret);
}
