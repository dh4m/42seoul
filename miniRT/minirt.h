/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:23:00 by dham              #+#    #+#             */
/*   Updated: 2023/04/02 14:28:20 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <pthread.h>

# define WIDTH 800
# define HEIGHT 600
# define REFL_NUM 2
# define SPARKLE_POWER 30
# define NUM_THREAD 16

enum e_return_value
{
	SUCCESS,
	RT_FILE_OPEN_ERROR = -1,
	UNAVILABLE_RT_FILE = -2,
	TEXTURE_FILE_OPEN_ERROR = -3,
	UNAVILABLE_TEXTURE_FILE = -4,
	FATAL_ERROR = -5,
	PARSING_SUCCESS = -6
};

enum e_contenttype
{
	LIGHT = 1,
	AMBIENT = 2,
	CAMERA = 3,
	OBJECT = 4,
};

enum e_shape
{
	UNKNOWN = 5,
	SPHERE = 6,
	PLANE = 7,
	CYLINDER = 8,
	CONE = 9
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
	int		reflect;
}	t_ray;

typedef struct s_camera
{
	int		active;
	t_vec	loc;
	t_vec	dir;
	int		fov;
	t_vec	hor;
	t_vec	ver;
}	t_camera;

typedef struct s_ambient
{
	int		active;
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
	int	width;
	int	height;
	int	**data;
}	t_texture;

typedef struct s_obj
{
	int				shape;
	t_vec			loc;
	float			diameter;
	float			height;
	t_color			color;
	float			reflection;
	t_vec			nomal_v;
	int				checker;
	t_texture		*texture;
	t_texture		*bump;
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

typedef struct s_hitpoint
{
	t_vec	nomal_v;
	t_vec	hit_p;
	t_color	point_color;
	t_vec	uv;
}	t_hitpoint;

typedef struct s_multithread_arg
{
	pthread_t	tid;
	int			max_x;
	t_content	*content;
	t_color		**buf;
}	t_multithread_arg;

void		invalid_args(void);
int			error_msg(int code, t_content *content);
int			clear_list(t_content *content);

void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
int			win_destroy(void *param);

int			make_image(t_img *img, const char *rt_file);
int			draw_img(t_img *img, t_content *content);
float		cam_obj_distance(t_ray *ray, t_obj *obj);
t_color		ray_calculate(int x, int y, t_content *content);

int			parsing(const char *rt_file, t_content *content);
void		camera_set(t_content *content);
void		obj_vec_nomalize(t_content *contect);

void		make_ray(int x, int y, t_ray *ray, t_content *content);
int			light_hit(t_light *light, t_vec *hit_p, \
						t_content *content, t_obj *hit_obj);
float		attenuation(t_light *light, t_hitpoint *hitinfo);

void		bright_set(t_color *color, float bright);
void		bright_modi(t_color *color, int max);
void		bright_normalize(t_content *content);
int			bright_color(t_color *color);

t_color		reflex_color(t_color *light, t_color *obj);
t_color		color_combine(t_color *a, t_color *b);
int			color_to_int(t_color *color);
t_color		int_to_color(int code);
t_color		color_reversal(t_color *origin);

void		buf_nomalize(t_color *buf[]);
int			buf_init(t_color *buf[]);

t_color		take_average(t_color buf[][2]);
t_color		antialiasing_color(int x, int y, t_content *content);

void		*multi_threading_draw(void *args);
void		buf_drawing(t_color *buf[], t_content *content);

int			eq_f(float a, float b);
float		square_f(float a);

t_vec		vec_multi(t_vec *vec, float f);
float		vec_inner(const t_vec *vec1, const t_vec *vec2);
t_vec		vec_cross(const t_vec *vec1, const t_vec *vec2);
t_vec		vec_plus(const t_vec *vec1, const t_vec *vec2);
t_vec		vec_minus(const t_vec *vec1, const t_vec *vec2);
float		vec_square(const t_vec *vec);
float		vector_size(const t_vec *vec);
void		vector_normalize(t_vec *vec);
float		distance_point(t_vec *v1, t_vec *v2);

float		sphere_distance(t_ray *ray, t_obj *obj);
t_vec		sphere_nomal_v(t_vec *hit_p, t_obj *hit_obj);

float		cone_distance(t_ray *ray, t_obj *obj);
t_vec		cone_nomal_v(t_vec *hit_p, t_obj *hit_obj);

float		cylinder_distance(t_ray *ray, t_obj *obj);
t_vec		cylinder_nomal_v(t_vec *hit_p, t_obj *hit_obj);

float		plane_distance(t_ray *ray, t_obj *obj);
t_vec		plane_nomal_v(t_obj *hit_obj);

t_color		reflect_value(t_hitpoint *hitinfo, \
							t_content *content, t_ray *ray_origin);
t_color		specular_value(t_hitpoint *hitinfo, \
							t_content *content, t_ray *ray_origin, t_obj *obj);

t_color		diffuse_value(t_hitpoint *hitinfo, \
							t_content *content, t_obj *hit_obj);

t_color		color_cal(t_ray *ray, float t, t_content *content, t_obj *hit_obj);
t_color		mapped_color(t_hitpoint *hitinfo, t_obj *obj);
t_vec		nomal_v_cal(t_hitpoint *hitinfo, t_obj *hit_obj, t_vec *ray_dir);

t_vec		uv_calculate(t_vec *hit_p, t_obj *obj);
void		texture_free(t_texture *t);

t_texture	*bmp_texture(const char *bmp_file);

// parsing part
void		ft_split_free(char **str);
int			ft_array_len(char **str);
int			open_rtfile(const char *rt_file);

int			parse_ambient(const char **str, t_ambient *ambient);
int			parse_camera(const char **str, t_camera *camera);
int			parse_light(const char **str, t_light *light);
int			parse_objects(const char **str, t_obj *obj, int type);

int			init_color(char *tmp, t_color *color);
int			init_point(char *arg1, t_vec *vec);

t_obj		*get_last_obj(t_obj *obj);
int			init_nomal_vector(char *str, t_vec *v);

#endif
