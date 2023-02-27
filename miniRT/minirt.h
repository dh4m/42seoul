/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:23:00 by dham              #+#    #+#             */
/*   Updated: 2023/02/27 18:50:03 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 800
# define HEIGHT 600

enum e_return_value
{
	SUCCESS,
	RT_FILE_OPEN_ERROR = -1,
	UNAVILABLE_RT_FILE = -2,
	TEXTURE_FILE_OPEN_ERROR = -3,
	UNAVILABLE_TEXTURE_FILE = -4,
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
	t_vec	hor;
	t_vec	ver;
}	t_camera;

typedef struct s_ambient
{
	float	bright;
	t_color	color;
}	t_ambient;

typedef struct s_light
{
	t_vec			loc;
	t_color			color;
	float			bright;
	struct s_light	*next;
}	t_light;

typedef struct s_texture
{
	int dummy;/////
}	t_texture;

typedef struct s_obj
{
	int				shape;
	t_vec			loc;
	float			diameter;
	float			height;
	float			theta;
	t_color			color;
	t_vec			nomal_v;
	t_texture		texture;
	t_texture		bump;
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

typedef struct s_content
{
	t_obj		obj_list;
	t_light		light_list;
	t_camera	camera;
	t_ambient	ambient;
}	t_content;


void	invalid_args(void);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		win_destroy(void *param);
void	bright_normalize(t_content *content);

int		make_image(t_info *info, t_img *img, const char *rt_file);
int		draw_img(t_info *info, t_img *img, t_content *content);
float	cam_obj_distance(t_ray *ray, t_obj *obj);

int		parsing(const char *rt_file, t_content *content);
int		ray_calculate(int x, int y, t_content *content);
int		clear_list(t_content *content);
float	vector_size(const t_vec *vec);
void	vector_normalize(t_vec *vec);
void	make_ray(int x, int y, t_ray *ray, t_content *content);
void	camera_set(t_content *content);

int		eq_f(float a, float b);

t_vec	vec_multi(t_vec *vec, float f);
float	vec_inner(const t_vec *vec1, const t_vec *vec2);
t_vec	vec_cross(const t_vec *vec1, const t_vec *vec2);
t_vec	vec_plus(const t_vec *vec1, const t_vec *vec2);
t_vec	vec_minus(const t_vec *vec1, const t_vec *vec2);

#endif
