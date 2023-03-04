/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:34:06 by dham              #+#    #+#             */
/*   Updated: 2023/03/04 14:26:08 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include "libft.h"

int	parsing(const char *rt_file, t_content *content)
{
	(void) rt_file;
	
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
	content->light_list.next = ft_calloc(1, sizeof(t_light));
	content->light_list.next->bright = 1.0;
	content->light_list.next->color.r = 255;
	content->light_list.next->color.g = 255;
	content->light_list.next->color.b = 255;
	content->light_list.next->loc.x = -5;
	content->light_list.next->loc.y = 10;
	content->light_list.next->loc.z = 10;

	// light 2 - 버그있음
	content->light_list.next->next = ft_calloc(1, sizeof(t_light));
	content->light_list.next->next->bright = 1.0;
	content->light_list.next->next->color.r = 255;
	content->light_list.next->next->color.g = 255;
	content->light_list.next->next->color.b = 255;
	content->light_list.next->next->loc.x = -5;
	content->light_list.next->next->loc.y = -10;
	content->light_list.next->next->loc.z = 10;

	// obj 1
	content->obj_list.next = ft_calloc(1, sizeof(t_obj));
	content->obj_list.next->shape = SPHERE;
	content->obj_list.next->loc.x = 5;
	content->obj_list.next->loc.y = 0;
	content->obj_list.next->loc.z = 0;
	content->obj_list.next->color.r = 255;
	content->obj_list.next->color.g = 255;
	content->obj_list.next->color.b = 255;
	content->obj_list.next->reflection = 1;
	content->obj_list.next->sparkle = 30;
	content->obj_list.next->diameter = 3;

	// obj 2
	content->obj_list.next->next = ft_calloc(1, sizeof(t_obj));
	content->obj_list.next->next->shape = SPHERE;
	content->obj_list.next->next->loc.x = 3;
	content->obj_list.next->next->loc.y = 1;
	content->obj_list.next->next->loc.z = 0.5;
	content->obj_list.next->next->color.r = 255;
	content->obj_list.next->next->color.g = 255;
	content->obj_list.next->next->color.b = 100;
	content->obj_list.next->next->reflection = 0.4;
	content->obj_list.next->next->sparkle = 30;
	content->obj_list.next->next->diameter = 1;

	// obj 3
	content->obj_list.next->next->next = ft_calloc(1, sizeof(t_obj));
	content->obj_list.next->next->next->shape = SPHERE;
	content->obj_list.next->next->next->loc.x = 3;
	content->obj_list.next->next->next->loc.y = -1.5;
	content->obj_list.next->next->next->loc.z = -1;
	content->obj_list.next->next->next->color.r = 255;
	content->obj_list.next->next->next->color.g = 100;
	content->obj_list.next->next->next->color.b = 255;
	content->obj_list.next->next->next->reflection = 0;
	content->obj_list.next->next->next->sparkle = 30;
	content->obj_list.next->next->next->diameter = 1;


	// obj 4
	content->obj_list.next->next->next->next = ft_calloc(1, sizeof(t_obj));
	content->obj_list.next->next->next->next->shape = PLANE;
	content->obj_list.next->next->next->next->loc.x = 0;
	content->obj_list.next->next->next->next->loc.y = 0;
	content->obj_list.next->next->next->next->loc.z = -1.6;
	content->obj_list.next->next->next->next->nomal_v.x = 0;
	content->obj_list.next->next->next->next->nomal_v.y = 0;
	content->obj_list.next->next->next->next->nomal_v.z = 1;
	content->obj_list.next->next->next->next->color.r = 200;
	content->obj_list.next->next->next->next->color.g = 255;
	content->obj_list.next->next->next->next->color.b = 255;
	content->obj_list.next->next->next->next->reflection = 0.4;
	content->obj_list.next->next->next->next->sparkle = 30;
	content->obj_list.next->next->next->next->diameter = -1;

	// obj 5
	content->obj_list.next->next->next->next->next = ft_calloc(1, sizeof(t_obj));
	content->obj_list.next->next->next->next->next->shape = PLANE;
	content->obj_list.next->next->next->next->next->loc.x = 25;
	content->obj_list.next->next->next->next->next->loc.y = 0;
	content->obj_list.next->next->next->next->next->loc.z = 0;
	content->obj_list.next->next->next->next->next->nomal_v.x = -1;
	content->obj_list.next->next->next->next->next->nomal_v.y = 0;
	content->obj_list.next->next->next->next->next->nomal_v.z = 0;
	content->obj_list.next->next->next->next->next->color.r = 255;
	content->obj_list.next->next->next->next->next->color.g = 255;
	content->obj_list.next->next->next->next->next->color.b = 255;
	content->obj_list.next->next->next->next->next->reflection = 0.1;
	content->obj_list.next->next->next->next->next->sparkle = 30;
	content->obj_list.next->next->next->next->next->diameter = 40;

	// obj 6
	content->obj_list.next->next->next->next->next->next = ft_calloc(1, sizeof(t_obj));
	content->obj_list.next->next->next->next->next->next->shape = CYLINDER;
	content->obj_list.next->next->next->next->next->next->loc.x = 3;
	content->obj_list.next->next->next->next->next->next->loc.y = 2;
	content->obj_list.next->next->next->next->next->next->loc.z = -1.6;
	content->obj_list.next->next->next->next->next->next->nomal_v.x = 0;
	content->obj_list.next->next->next->next->next->next->nomal_v.y = 0;
	content->obj_list.next->next->next->next->next->next->nomal_v.z = 1;
	content->obj_list.next->next->next->next->next->next->color.r = 255;
	content->obj_list.next->next->next->next->next->next->color.g = 255;
	content->obj_list.next->next->next->next->next->next->color.b = 255;
	content->obj_list.next->next->next->next->next->next->reflection = 0.7;
	content->obj_list.next->next->next->next->next->next->sparkle = 30;
	content->obj_list.next->next->next->next->next->next->diameter = 0.5;
	content->obj_list.next->next->next->next->next->next->height = 10;

	return (SUCCESS);
}