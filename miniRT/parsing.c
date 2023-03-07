/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:34:06 by dham              #+#    #+#             */
/*   Updated: 2023/03/08 00:54:16 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"

void	insert_content_list(t_content *content, int type, void *object)
{
	t_light	*light;
	t_obj	*obj;

	if (type == LIGHT)
	{
		light = &content->light_list;
		while (light->next)
			light = light->next;
		light->next = (t_light*)object;
		light->next->next = NULL;
	}
	else if (type == OBJECT)
	{
		obj = &content->obj_list;
		while (obj->next)
			obj = obj->next;
		obj->next = (t_obj*)object;
		obj->next->next = NULL;
	}
}

int	parsing(const char *rt_file, t_content *content)
{
	(void) rt_file;
	t_light	*temp_l;
	t_obj	*temp_o;
	
	// camera
	content->camera.loc.x = 0;
	content->camera.loc.y = 0;
	content->camera.loc.z = 0;
	content->camera.dir.x = 1;
	content->camera.dir.y = 0;
	content->camera.dir.z = 0;
	content->camera.fov = 120;
	
	// ambient
	content->ambient.bright = 0.2;
	content->ambient.color.r = 255;
	content->ambient.color.g = 255;
	content->ambient.color.b = 255;

	// light 1
	temp_l = ft_calloc(1, sizeof(t_light));
	temp_l->bright = 100.0;
	temp_l->color.r = 255;
	temp_l->color.g = 255;
	temp_l->color.b = 255;
	temp_l->loc.x = -5;
	temp_l->loc.y = 10;
	temp_l->loc.z = 10;
	insert_content_list(content, LIGHT, temp_l);

	// light 2
	temp_l = ft_calloc(1, sizeof(t_light));
	temp_l->bright = 100.0;
	temp_l->color.r = 255;
	temp_l->color.g = 255;
	temp_l->color.b = 255;
	temp_l->loc.x = -5;
	temp_l->loc.y = -10;
	temp_l->loc.z = 10;
	insert_content_list(content, LIGHT, temp_l);

	// obj 1
	temp_o = ft_calloc(1, sizeof(t_obj));
	temp_o->shape = SPHERE;
	temp_o->loc.x = 5;
	temp_o->loc.y = 0;
	temp_o->loc.z = 0;
	temp_o->color.r = 255;
	temp_o->color.g = 255;
	temp_o->color.b = 255;
	temp_o->reflection = 0;
	temp_o->diameter = 3;
	temp_o->checker = 1;
	insert_content_list(content, OBJECT, temp_o);

	// obj 2
	temp_o = ft_calloc(1, sizeof(t_obj));
	temp_o->shape = SPHERE;
	temp_o->loc.x = 3;
	temp_o->loc.y = 1;
	temp_o->loc.z = 0.5;
	temp_o->color.r = 255;
	temp_o->color.g = 255;
	temp_o->color.b = 100;
	temp_o->reflection = 0.4;
	temp_o->diameter = 1;
	insert_content_list(content, OBJECT, temp_o);

	// obj 3
	temp_o = ft_calloc(1, sizeof(t_obj));
	temp_o->shape = SPHERE;
	temp_o->loc.x = 3;
	temp_o->loc.y = -1.5;
	temp_o->loc.z = -1;
	temp_o->color.r = 255;
	temp_o->color.g = 100;
	temp_o->color.b = 255;
	temp_o->reflection = 0;
	temp_o->diameter = 1;
	insert_content_list(content, OBJECT, temp_o);


	// obj 4
	temp_o = ft_calloc(1, sizeof(t_obj));
	temp_o->shape = PLANE;
	temp_o->loc.x = 0;
	temp_o->loc.y = 0;
	temp_o->loc.z = -1.6;
	temp_o->nomal_v.x = 0;
	temp_o->nomal_v.y = 0;
	temp_o->nomal_v.z = 1;
	temp_o->color.r = 200;
	temp_o->color.g = 255;
	temp_o->color.b = 255;
	temp_o->reflection = 0.4;
	temp_o->diameter = -1;
	temp_o->checker = 1;
	insert_content_list(content, OBJECT, temp_o);

	// obj 5
	temp_o = ft_calloc(1, sizeof(t_obj));
	temp_o->shape = PLANE;
	temp_o->loc.x = 25;
	temp_o->loc.y = 0;
	temp_o->loc.z = 0;
	temp_o->nomal_v.x = 1;
	temp_o->nomal_v.y = 0;
	temp_o->nomal_v.z = 0;
	temp_o->color.r = 255;
	temp_o->color.g = 255;
	temp_o->color.b = 255;
	temp_o->reflection = 0;
	temp_o->diameter = 40;
	insert_content_list(content, OBJECT, temp_o);

	// obj 6
	temp_o = ft_calloc(1, sizeof(t_obj));
	temp_o->shape = CYLINDER;
	temp_o->loc.x = 3;
	temp_o->loc.y = 2;
	temp_o->loc.z = -1.6;
	temp_o->nomal_v.x = 0;
	temp_o->nomal_v.y = 0;
	temp_o->nomal_v.z = 1;
	temp_o->color.r = 255;
	temp_o->color.g = 255;
	temp_o->color.b = 255;
	temp_o->reflection = 0.2;
	temp_o->diameter = 2;
	temp_o->height = 1;
	temp_o->checker = 1;
	insert_content_list(content, OBJECT, temp_o);

	// obj 7
	temp_o = ft_calloc(1, sizeof(t_obj));
	temp_o->shape = CONE;
	temp_o->loc.x = 3;
	temp_o->loc.y = 0;
	temp_o->loc.z = -0.6;
	temp_o->nomal_v.x = 0;
	temp_o->nomal_v.y = 0;
	temp_o->nomal_v.z = -1;
	temp_o->color.r = 255;
	temp_o->color.g = 255;
	temp_o->color.b = 255;
	temp_o->reflection = 0.2;
	temp_o->diameter = 0.8;
	temp_o->height = 1;
	temp_o->checker = 1;
	insert_content_list(content, OBJECT, temp_o);

	return (SUCCESS);
}