/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinam <jinam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:20:23 by jinam             #+#    #+#             */
/*   Updated: 2023/03/14 12:11:39 by jinam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minirt.h"
#include <stdio.h>

static int	_init_dir(char *str2, t_camera *camera)
{
	const char	**arg2 = (const char **)ft_split(str2, ',');

	if (ft_array_len((char **)arg2) != 3)
	{
		ft_split_free((char **)arg2);
		return (UNAVILABLE_RT_FILE);
	}
	camera->dir.x = ft_atof(arg2[0]);
	camera->dir.y = ft_atof(arg2[1]);
	camera->dir.z = ft_atof(arg2[2]);
	ft_split_free((char **)arg2);
	if (camera->dir.x < -1 || camera->dir.x > 1)
		return (UNAVILABLE_RT_FILE);
	if (camera->dir.y < -1 || camera->dir.y > 1)
		return (UNAVILABLE_RT_FILE);
	if (camera->dir.z < -1 || camera->dir.z > 1)
		return (UNAVILABLE_RT_FILE);
	return (SUCCESS);
}

static int	_init_fov(char *arg3, t_camera *camera)
{
	camera->fov = ft_atoi(arg3);
	if (camera->fov <= 0 || camera->fov >= 180)
		return (UNAVILABLE_RT_FILE);
	return (SUCCESS);
}

int	parse_camera(const char **str, t_camera *camera)
{
	const int	len = ft_array_len((char **)str);

	if (camera->active == PARSING_SUCCESS)
		return (UNAVILABLE_RT_FILE);
	camera->active = PARSING_SUCCESS;
	if (len != 4)
		return (UNAVILABLE_RT_FILE);
	if (init_point((char *)str[1], &camera->loc) == RT_FILE_OPEN_ERROR)
		return (UNAVILABLE_RT_FILE);
	if (_init_dir((char *)str[2], camera) == RT_FILE_OPEN_ERROR)
		return (UNAVILABLE_RT_FILE);
	return (_init_fov((char *)str[3], camera));
}
