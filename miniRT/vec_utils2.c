/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:40:56 by dham              #+#    #+#             */
/*   Updated: 2023/03/19 16:51:48 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>

float	vector_size(const t_vec *vec)
{
	return (sqrtf(square_f(vec->x) + square_f(vec->y) + square_f(vec->z)));
}

void	vector_normalize(t_vec *vec)
{
	const float	len = vector_size(vec);

	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

float	vec_square(const t_vec *vec)
{
	return (square_f(vec->x) + square_f(vec->y) + square_f(vec->z));
}

float	distance_point(t_vec *v1, t_vec *v2)
{
	t_vec	temp;

	temp = vec_minus(v2, v1);
	return (vector_size(&temp));
}
