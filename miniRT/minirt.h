/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:23:00 by dham              #+#    #+#             */
/*   Updated: 2023/02/21 17:14:38 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define SCREEN_SIZE 800

enum asdf/////

typedef struct s_vec
{
	double x;
	double y;
	double z;
}	t_vec;

typedef struct s_ray
{
	t_vec start;
	t_vec dir;
}	t_rey;

typedef struct s_obj
{
	t_vec 
}	t_obj;

typedef struct s_info
{
	void		*mlx;
	void		*win;
}	t_info;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

void	invalid_args(void);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		win_destroy(void *param);

#endif
