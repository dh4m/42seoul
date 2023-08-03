/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:01:35 by jinam             #+#    #+#             */
/*   Updated: 2023/04/08 20:19:30 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minirt.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h> 

void	ft_split_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i ++;
	}
	free(str);
}

int	init_color(char *str, t_color *color)
{
	char	**tmp;

	tmp = ft_split(str, ',');
	if (ft_array_len(tmp) != 3)
	{
		ft_split_free(tmp);
		return (UNAVILABLE_RT_FILE);
	}
	color->r = ft_atoi(tmp[0]);
	color->g = ft_atoi(tmp[1]);
	color->b = ft_atoi(tmp[2]);
	ft_split_free(tmp);
	if (color->r < 0 || color->r > 255)
		return (UNAVILABLE_RT_FILE);
	if (color->g < 0 || color->g > 255)
		return (UNAVILABLE_RT_FILE);
	if (color->b < 0 || color->b > 255)
		return (UNAVILABLE_RT_FILE);
	return (SUCCESS);
}

int	init_point(char *str, t_vec *loc)
{
	char	**arg1;

	arg1 = ft_split(str, ',');
	if (ft_array_len(arg1) != 3)
	{
		ft_split_free(arg1);
		return (UNAVILABLE_RT_FILE);
	}
	loc->x = ft_atof(arg1[0]);
	loc->y = ft_atof(arg1[1]);
	loc->z = ft_atof(arg1[2]);
	ft_split_free(arg1);
	return (SUCCESS);
}

int	ft_array_len(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i ++;
	return (i);
}

int	open_rtfile(const char *rt_file)
{
	char	*str;
	int		fd;

	str = ft_strjoin("./rt_file/", rt_file);
	fd = open(str, O_RDONLY);
	free(str);
	return (fd);
}
