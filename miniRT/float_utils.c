/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:07:23 by dham              #+#    #+#             */
/*   Updated: 2023/03/18 14:25:33 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>

int	eq_f(float a, float b)
{
	if (a >= b)
		return ((a - b) < __FLT_EPSILON__);
	return ((b - a) < __FLT_EPSILON__);
}

float	square_f(float a)
{
	return (a * a);
}
