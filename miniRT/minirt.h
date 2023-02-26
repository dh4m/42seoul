/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:23:00 by dham              #+#    #+#             */
/*   Updated: 2023/02/22 22:38:50 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1200
# define HEIGHT 800

enum e_return_value
{
	SUCCESS,
	RT_FILE_OPEN_ERROR = -1,
	UNAVILABLE_RT_FILE = -2,
	TEXTURE_FILE_OPEN_ERROR = -3,
	UNAVILABLE_RT_FILE = -4,
	FATAL_ERROR = -5
};

enum e_shape
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
};

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_ray
{
	t_vec	start;
	t_vec	dir;
}	t_ray;

typedef struct s_camera
{
	t_vec	loc;
	t_vec	dir;
	int		fov;
}	t_camera;

typedef struct s_light
{
	int				ambient;
	t_vec			loc;
	t_color			color;
	float			bright;
	struct s_light	*next;
}	t_light;

typedef struct s_obj
{
	int				shape;
	t_vec			loc;
	float			diameter;
	float			height;
	float			theta;
	t_color			color;
	t_vec			nomal_v;
	//				texture
	//				bump map texture
	struct s_obj	*next;
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

int		make_image(t_info *info, t_img *img, char *rt_file);

#endif
