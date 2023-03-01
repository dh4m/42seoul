/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:34:06 by dham              #+#    #+#             */
/*   Updated: 2023/03/01 19:33:56 by dham             ###   ########.fr       */
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
	content->light_list.next->loc.x = -1;
	content->light_list.next->loc.y = 4;
	content->light_list.next->loc.z = 10;

	// light 2 - 버그있음
	content->light_list.next->next = ft_calloc(1, sizeof(t_light));
	content->light_list.next->next->bright = 1.0;
	content->light_list.next->next->color.r = 255;
	content->light_list.next->next->color.g = 255;
	content->light_list.next->next->color.b = 255;
	content->light_list.next->next->loc.x = 3;
	content->light_list.next->next->loc.y = 0;
	content->light_list.next->next->loc.z = -2;

	// obj 1
	content->obj_list.next = ft_calloc(1, sizeof(t_obj));
	content->obj_list.next->shape = SPHERE;
	content->obj_list.next->loc.x = 5;
	content->obj_list.next->loc.y = 0;
	content->obj_list.next->loc.z = 0;
	content->obj_list.next->color.r = 255;
	content->obj_list.next->color.g = 255;
	content->obj_list.next->color.b = 255;
	content->obj_list.next->reflection = 0.2;
	content->obj_list.next->diameter = 3;

	// obj 2
	content->obj_list.next->next = ft_calloc(1, sizeof(t_obj));
	content->obj_list.next->next->shape = SPHERE;
	content->obj_list.next->next->loc.x = 3;
	content->obj_list.next->next->loc.y = 0;
	content->obj_list.next->next->loc.z = 0;
	content->obj_list.next->next->color.r = 255;
	content->obj_list.next->next->color.g = 0;
	content->obj_list.next->next->color.b = 0;
	content->obj_list.next->next->reflection = 0.2;
	content->obj_list.next->next->diameter = 1;
/*
	// obj 3
	content->obj_list.next->next->next = ft_calloc(1, sizeof(t_obj));
	content->obj_list.next->next->next->shape = SPHERE;
	content->obj_list.next->next->next->loc.x = 4.8;
	content->obj_list.next->next->next->loc.y = -1.5;
	content->obj_list.next->next->next->loc.z = -1;
	content->obj_list.next->next->next->color.r = 255;
	content->obj_list.next->next->next->color.g = 255;
	content->obj_list.next->next->next->color.b = 255;
	content->obj_list.next->reflection = 0.2;
	content->obj_list.next->next->next->diameter = 2;
*/

	return (SUCCESS);
}