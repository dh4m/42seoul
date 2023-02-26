/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:49:43 by dham              #+#    #+#             */
/*   Updated: 2023/02/26 20:24:46 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

enum	e_map_element
{
	NORTH_T,
	SOUTH_T,
	EAST_T,
	WEST_T,
	FLOOR_COLOR,
	CEILING_COLOR
};

typedef struct s_map
{
	char			**map;
	char			*north_texture;
	char			*south_texture;
	char			*east_texture;
	char			*west_texture;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
}	t_map;

int		parsing_file(t_map *map, char *m_file);

int		filename_check(char *name);
int		info_category(char *str);
void	map_set(t_map *map);
int		valid_num(char **sp);
int		dup_check(t_map *map, int cat);

char	*ft_readline(int fd);
int		free_split(char **sp);

int		map_content(int fd, t_map *map);

#endif