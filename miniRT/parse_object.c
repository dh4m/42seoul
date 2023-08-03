/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:22:16 by jinam             #+#    #+#             */
/*   Updated: 2023/03/19 16:09:41 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
#include "libft/libft.h"

int	init_obj_texture_file(char **str, t_obj *obj)
{
	if (!str[0] || !str[1])
		return (UNAVILABLE_RT_FILE);
	if (ft_strncmp(str[0], "0", 2))
	{
		obj->texture = bmp_texture(str[0]);
		if (!obj->texture)
			return (UNAVILABLE_TEXTURE_FILE);
	}
	if (ft_strncmp(str[1], "0", 2))
	{
		obj->bump = bmp_texture(str[1]);
		if (!obj->bump)
			return (UNAVILABLE_TEXTURE_FILE);
	}
	return (SUCCESS);
}

//loc diameter height color reflection normal_vector checker texture bump
int	init_obj_common(int type, char **str, t_obj *obj)
{
	int	i;

	obj->shape = type;
	i = 1;
	if (init_point(str[i++], &obj->loc) == UNAVILABLE_RT_FILE)
		return (UNAVILABLE_RT_FILE);
	obj->diameter = ft_atof(str[i++]);
	if ((type == PLANE && obj->diameter < -1) || \
		(type != PLANE && obj->diameter < 0))
		return (UNAVILABLE_RT_FILE);
	if (type != PLANE && type != SPHERE)
		obj->height = ft_atoi(str[i++]);
	if (init_color(str[i++], &obj->color) == UNAVILABLE_RT_FILE)
		return (UNAVILABLE_RT_FILE);
	obj->reflection = ft_atof(str[i++]);
	if (obj->reflection < 0 || obj->reflection > 1)
		return (UNAVILABLE_RT_FILE);
	if (type != SPHERE)
		if (init_nomal_vector(str[i++], &obj->nomal_v) == UNAVILABLE_RT_FILE)
			return (UNAVILABLE_RT_FILE);
	obj->checker = ft_atoi(str[i++]);
	if (init_obj_texture_file(&str[i], obj) != SUCCESS)
		return (UNAVILABLE_RT_FILE);
	return (SUCCESS);
}

// 10 
// plane = 9
// sphere = 8

int	parse_objects(const char **str, t_obj *obj, int type)
{
	t_obj		*tmp;
	const int	len = ft_array_len((char **)str);

	if ((type == PLANE && len != 9) || (type == SPHERE && len != 8))
		return (UNAVILABLE_RT_FILE);
	else if ((type != PLANE && type != SPHERE) && len != 10)
		return (UNAVILABLE_RT_FILE);
	tmp = ft_calloc(sizeof(t_obj), 1);
	if (!tmp)
		return (FATAL_ERROR);
	if (init_obj_common(type, (char **)str, tmp) != SUCCESS)
	{
		free(tmp);
		return (UNAVILABLE_RT_FILE);
	}
	get_last_obj(obj)->next = tmp;
	return (SUCCESS);
}
