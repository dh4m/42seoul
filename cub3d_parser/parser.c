/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:54:09 by dham              #+#    #+#             */
/*   Updated: 2023/02/26 20:23:25 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <unistd.h>
#include <fcntl.h>

int	clear_map(t_map *map)
{
	if (map->north_texture)
		free(map->north_texture);
	if (map->south_texture)
		free(map->south_texture);
	if (map->west_texture)
		free(map->west_texture);
	if (map->east_texture)
		free(map->east_texture);
	return (1);
}

int	color_write(t_map *map, char **sp, int cat)
{
	int	color;
	
	if (!valid_num(sp))
		return (0);
	color = (ft_atoi(sp[1]) << 16) + (ft_atoi(sp[2]) << 8) + ft_atoi(sp[3]);
	if (cat == FLOOR_COLOR)
		map->floor_color = color;
	if (cat == CEILING_COLOR)
		map->ceiling_color = color;
}

int	info_write(t_map *map, char *str, int cat)
{
	char	**sp;

	sp = ft_split(str, ' ');
	if (!(cat == FLOOR_COLOR || cat == CEILING_COLOR) && \
		(!sp[1] || sp[2]) && free_split(sp))
		return (-1);
	if (!dup_check(map, cat) && free_split(sp))
		return (-1);
	if (cat == NORTH_T)
		map->north_texture = ft_strdup(sp[1]);
	else if (cat == SOUTH_T)
		map->south_texture = ft_strdup(sp[1]);
	else if (cat == EAST_T)
		map->east_texture = ft_strdup(sp[1]);
	else if (cat == WEST_T)
		map->west_texture = ft_strdup(sp[1]);
	else if (cat == FLOOR_COLOR || cat == CEILING_COLOR)
		if (!color_write(map, sp, cat) && free_split(sp))
			return (-1);
	free_split(sp);
	return (0);
}

int	map_info(int fd, t_map *map)
{
	char			*str;
	int				category;
	unsigned char	info_fill;

	info_fill = 0;
	str = ft_readline(fd);
	category = info_category(str);
	while (category >= 0)
	{
		if (info_write(map, str, category) < 0)
		{
			free(str);
			return (0);
		}
		info_fill |= (1 << category);
		if (info_fill == (1 << 6) - 1)
			break;
		free(str);
		str = ft_readline(fd);
		category = info_category(str);
	}
	if (str)
		free(str);
	return (1);
}

//usage: t_map 변수를 생성 후 그 주소를 해당 함수에 argv[1] 과 함께 넘길 것
// 정상 작동 시 0 return, 파싱 오류 시 -1 리턴
int	parsing_file(t_map *map, char *m_file)
{
	int	fd;

	map_set(map);
	if (!filename_check(m_file))
		return (-1);
	fd = open(m_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (!map_info(fd, map) && clear_map(map))
		return (-1);
	if (!map_content(fd, map) && clear_map(map))
		return (-1);
	return (0);
}