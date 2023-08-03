/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:34:06 by dham              #+#    #+#             */
/*   Updated: 2023/04/02 16:12:53 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "minirt.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

void	insert_content_list(t_content *content, int type, void *object)
{
	t_light	*light;
	t_obj	*obj;

	if (type == LIGHT)
	{
		light = &content->light_list;
		while (light->next)
			light = light->next;
		light->next = (t_light *)object;
		light->next->next = NULL;
	}
	else if (type == OBJECT)
	{
		obj = &content->obj_list;
		while (obj->next)
			obj = obj->next;
		obj->next = (t_obj *)object;
		obj->next->next = NULL;
	}
}

int	check_type(char *str)
{
	if (!str)
		return (UNKNOWN);
	else if (str[0] == 'A')
		return (AMBIENT);
	else if (str[0] == 'C')
		return (CAMERA);
	else if (str[0] == 'L')
		return (LIGHT);
	else if (ft_strncmp(str, "sp", 3) == 0)
		return (SPHERE);
	else if (ft_strncmp(str, "pl", 3) == 0)
		return (PLANE);
	else if (ft_strncmp(str, "cy", 3) == 0)
		return (CYLINDER);
	else if (ft_strncmp(str, "co", 3) == 0)
		return (CONE);
	else
		return (UNKNOWN);
}

int	parsing_str(char *str, t_content *content)
{
	const char	**token = (const char **)ft_split(str, ' ');
	const int	type = check_type((char *)token[0]);
	int			res;

	if (type == AMBIENT)
		res = parse_ambient(token, &content->ambient);
	else if (type == CAMERA)
		res = parse_camera(token, &content->camera);
	else if (type == LIGHT)
		res = parse_light(token, &content->light_list);
	else if (type != UNKNOWN)
		res = parse_objects(token, &content->obj_list, type);
	else
	{
		ft_split_free((char **)token);
		free(str);
		return (UNAVILABLE_RT_FILE);
	}
	ft_split_free((char **)token);
	free(str);
	return (res);
}

int	_ignore_str(char *str)
{
	if (str[0] == '/' || str[0] == '\n')
	{
		free(str);
		return (1);
	}
	return (0);
}

int	parsing(const char *rt_file, t_content *content)
{
	int			fd;
	int			res;
	char		*str;
	const int	file_len = ft_strlen(rt_file);

	if (file_len <= 3 || ft_strncmp(&rt_file[file_len - 3], ".rt", 3))
		return (RT_FILE_OPEN_ERROR);
	fd = open_rtfile(rt_file);
	if (fd < 0)
		return (RT_FILE_OPEN_ERROR);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (_ignore_str(str))
			continue ;
		str[ft_strlen(str) - 1] = 0;
		res = parsing_str(str, content);
		if (res != SUCCESS)
			return (res);
	}
	if (content->camera.active != PARSING_SUCCESS)
		return (RT_FILE_OPEN_ERROR);
	return (SUCCESS);
}
