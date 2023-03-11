/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:40:28 by dham              #+#    #+#             */
/*   Updated: 2023/03/11 16:35:20 by dham             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	size_check(int fd, int idx)
{
	unsigned int	size;
	unsigned int	buf;

	size = 0;
	buf = 0;
	lseek(fd, idx, SEEK_SET);
	read(fd, &buf, 4);
	size = buf;
	return (size);
}

int	init_texture_data(t_texture *texture, int width, int height)
{
	int	i;
	int	free_i;

	texture->data = malloc(sizeof(int *) * height);
	if (!texture->data)
		return (FATAL_ERROR);
	i = -1;
	while (++i < height)
	{
		texture->data[i] = malloc(sizeof(int) * width);
		if (!texture->data[i])
		{
			free_i = 0;
			while (free_i < i)
				free(texture->data[free_i]);
			free(texture->data);
			return (FATAL_ERROR);
		}
	}
	return (0);
}

int	texture_data_set(int fd, t_texture *texture)
{
	unsigned int	data;
	unsigned int	buf;
	int	i;
	int	j;

	i = texture->height;
	while (--i >= 0)
	{
		j = -1;
		while (++j < texture->width)
		{
			read(fd, &buf, 3);
			data = buf;
			/*
			data += (buf & 0xff00) << 8;
			data += (buf & 0xff0000) >> 8;
			data += (buf & 0xff000000) >> 24;
			*/
			texture->data[i][j] = data;
		}
		read(fd, &buf, (texture->width * 3) % 4);
	}
	return (0);
}

int	texture_set(int fd, t_texture *texture)
{
	unsigned char	buf[4];
	int				i;
	int				j;

	read(fd, buf, 2);
	if (buf[0] != 'B' || buf[1] != 'M')
		return (UNAVILABLE_TEXTURE_FILE);
	texture->width = size_check(fd, 18);
	texture->height = size_check(fd, 22);
	printf("%d %d\n", texture->width, texture->height);
	if (init_texture_data(texture, texture->width, texture->height) == FATAL_ERROR)
		return (FATAL_ERROR);
	lseek(fd, size_check(fd, 10), SEEK_SET);
	texture_data_set(fd, texture);
	return (0);
}

t_texture	*bmp_texture(const char *bmp_file)
{
	int			fd;
	t_texture	*ret_texture;

	fd = open(bmp_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ret_texture = malloc(sizeof(t_texture));
	if (texture_set(fd, ret_texture) < 0)
	{
		free(ret_texture);
		return(NULL);
	}
	close(fd);
	return (ret_texture);
}