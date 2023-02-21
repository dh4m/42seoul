/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:19:03 by dham              #+#    #+#             */
/*   Updated: 2023/02/21 17:14:42 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"

int	main(int argc, char *argv[])
{
	t_info info;

	if (argc != 2)
		invalid_args();
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, SCREEN_SIZE, SCREEN_SIZE, "miniRT");
	

	mlx_hook(info.win, 17, 0, win_destroy, 0);
	mlx_loop(info.mlx);
	return (0);
}