/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:31 by dham              #+#    #+#             */
/*   Updated: 2022/08/03 20:14:54 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <stdlib.h>

int	destroy(void *param)
{
	exit(0);
}

int	mouse_event(int botton, int x, int y, t_info *param)
{
	static void	(*func[3])(t_info *info) = {
		mangdelbrot, julia, custom
	};

	if (botton == 4)
		zoom_in(x, y, param);
	else if (botton == 5)
		zoom_out(x, y, param);
	else if (botton == 1 || botton == 2)
		color_shift(param);
	else if (botton == 3)
	{
		init_info(param);
		func[param->type](param);
	}
	return (0);
}

int	key_event(int keycode, t_info *param)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	else if (LEFT <= keycode && keycode <= UP)
	{
		moving_arrow(keycode, param);
	}
	return (0);
}

void	moving_arrow(int keycode, t_info *info)
{
	static void	(*func[3])(t_info *info) = {
		mangdelbrot, julia, custom
	};

	if (keycode == UP)
	{
		info->sp_y += (info->length / 100);
		func[info->type](info);
	}
	else if (keycode == DOWN)
	{
		info->sp_y -= (info->length / 100);
		func[info->type](info);
	}
	else if (keycode == LEFT)
	{
		info->sp_x -= (info->length / 100);
		func[info->type](info);
	}
	else if (keycode == RIGHT)
	{
		info->sp_x += (info->length / 100);
		func[info->type](info);
	}
}

void	color_shift(t_info *info)
{
	static void	(*func[3])(t_info *info) = {
		mangdelbrot, julia, custom
	};

	info->color++;
	if (info->color > 15)
		info->color = 1;
	func[info->type](info);
}
