/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:07:23 by dham              #+#    #+#             */
/*   Updated: 2023/02/27 17:13:07 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>

int	eq_f(float a, float b)
{
	if (a >= b)
		return ((a - b) < 0.000001f);
	else if(b > a)
		return ((b - a) < 0.000001f);
}