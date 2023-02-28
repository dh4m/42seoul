/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:34:06 by dham              #+#    #+#             */
/*   Updated: 2023/03/01 04:36:01 by dham             ###   ########.fr       */
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
	content->camera.fov = 60;
	
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
	content->light_list.next->loc.x = 4;
	content->light_list.next->loc.y = 4;
	content->light_list.next->loc.z = 10;

	// light 2?????
	content->light_list.next->next = ft_calloc(1, sizeof(t_light));
	content->light_list.next->next->bright = 1.0;
	content->light_list.next->next->color.r = 255;
	content->light_list.next->next->color.g = 255;
	content->light_list.next->next->color.b = 255;
	content->light_list.next->next->loc.x = 5;
	content->light_list.next->next->loc.y = -10;
	content->light_list.next->next->loc.z = 0;

	// obj 1
	content->obj_list.next = ft_calloc(1, sizeof(t_obj));
	content->obj_list.next->shape = SPHERE;
	content->obj_list.next->loc.x = 5;
	content->obj_list.next->loc.y = 0;
	content->obj_list.next->loc.z = 0;
	content->obj_list.next->color.r = 207;
	content->obj_list.next->color.g = 255;
	content->obj_list.next->color.b = 229;
	content->obj_list.next->diameter = 3;
/*
	// obj 2
	content->obj_list.next->next = ft_calloc(1, sizeof(t_obj));
	content->obj_list.next->next->shape = SPHERE;
	content->obj_list.next->next->loc.x = 5;
	content->obj_list.next->next->loc.y = 3;
	content->obj_list.next->next->loc.z = 0;
	content->obj_list.next->next->color.r = 207;
	content->obj_list.next->next->color.g = 0;
	content->obj_list.next->next->color.b = 0;
	content->obj_list.next->next->diameter = 3;
*/

	return (SUCCESS);
}