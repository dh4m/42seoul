/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:57:17 by dham              #+#    #+#             */
/*   Updated: 2023/02/26 20:01:40 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

int	filename_check(char *name)
{
	const size_t	len = ft_strlen(name);

	if (ft_strncmp(&name[len - 4], ".cub", 5))
	{
		return (0);
	}
	return (1);
}

int	info_category(char *str)
{
	if (!str)
		return (-1);
	if (ft_strncmp(str, "NO ", 3) == 0)
		return (NORTH_T);
	if (ft_strncmp(str, "SO ", 3) == 0)
		return (SOUTH_T);
	if (ft_strncmp(str, "EA ", 3) == 0)
		return (EAST_T);
	if (ft_strncmp(str, "WE ", 3) == 0)
		return (WEST_T);
	if (ft_strncmp(str, "F ", 2) == 0)
		return (FLOOR_COLOR);
	if (ft_strncmp(str, "C ", 2) == 0)
		return (CEILING_COLOR);
	return (-1);
}

int		valid_num(char **sp)
{
	int	i;
	int	j;

	if (!sp[1] || !sp[2] || !sp[3] || sp[4])
		return (0);
	if (ft_atoi(sp[1]) < 0 || ft_atoi(sp[1]) > 255 || \
		ft_atoi(sp[2]) < 0 || ft_atoi(sp[2]) > 255 || \
		ft_atoi(sp[3]) < 0 || ft_atoi(sp[3]) > 255)
		return (0);
	i = 0;
	while (++i < 4)
	{
		j = 0;
		while (sp[i][j] && sp[i][j + 1])
		{
			if ('0' > sp[i][j] || '9' < sp[i][j])
				return (0);
			j++;
		}
		if (sp[i][j] != ',')
			return (0);
	}
	return (0);
}

int	dup_check(t_map *map, int cat)
{
	if (cat == NORTH_T && map->north_texture || \
		cat == SOUTH_T && map->south_texture || \
		cat == EAST_T && map->east_texture || \
		cat == WEST_T && map->west_texture || \
		cat == FLOOR_COLOR && map->floor_color != 0xffffffff || \
		cat == CEILING_COLOR && map->ceiling_color != 0xffffffff)
		return (0);
	return (1);
}

void	map_set(t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	map->floor_color = 0xffffffff;
	map->floor_color = 0xffffffff;
}