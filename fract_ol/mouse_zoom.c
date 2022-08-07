/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:21:58 by dham              #+#    #+#             */
/*   Updated: 2022/08/03 20:16:15 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

void	zoom_in(int x, int y, t_info *info)
{
	static void	(*func[3])(t_info *info) = {
		mangdelbrot, julia, custom
	};
	long double	e;

	e = info->length / LINE_LEN;
	info->length *= (9 / 10.);
	info->sp_x += e * (x - LINE_LEN / 2) * (1 / 10.);
	info->sp_y += e * (LINE_LEN / 2 - y) * (1 / 10.);
	func[info->type](info);
}

void	zoom_out(int x, int y, t_info *info)
{
	static void	(*func[3])(t_info *info) = {
		mangdelbrot, julia, custom
	};
	long double	e;

	e = info->length / LINE_LEN;
	info->length *= (10 / 9.);
	info->sp_x -= e * (x - LINE_LEN / 2) * (1 / 9.);
	info->sp_y -= e * (LINE_LEN / 2 - y) * (1 / 9.);
	func[info->type](info);
}
