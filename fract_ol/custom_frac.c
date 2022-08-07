/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_frac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:29:49 by dham              #+#    #+#             */
/*   Updated: 2022/08/03 20:13:50 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	custom_main(int argc, char *argv[])
{
	t_info	info;

	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, LINE_LEN, LINE_LEN, "fractol");
	init_info(&info);
	info.type = CUSTOM;
	custom(&info);
	mlx_key_hook(info.win, key_event, &info);
	mlx_mouse_hook(info.win, mouse_event, &info);
	mlx_hook(info.win, 17, 0, destroy, 0);
	mlx_loop(info.mlx);
	return (0);
}

void	custom(t_info *info)
{
	t_img	img;

	img.img = mlx_new_image(info->mlx, LINE_LEN, LINE_LEN);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
								&img.line_length, &img.endian);
	drawing_custom(info, &img);
	mlx_put_image_to_window(info->mlx, info->win, img.img, 0, 0);
}

void	drawing_custom(t_info *info, t_img *img)
{
	long double	e;
	int			x;
	int			y;
	int			iter_num;

	e = info->length / LINE_LEN;
	y = 0;
	while (y < LINE_LEN)
	{
		x = 0;
		while (x < LINE_LEN)
		{
			iter_num = custom_cal(0, 0, info->sp_x + (x - LINE_LEN / 2) * e, \
								info->sp_y + (LINE_LEN / 2 - y) * e);
			my_mlx_pixel_put(img, x, y, color_select(iter_num, info->color));
			x++;
		}
		y++;
	}
}
