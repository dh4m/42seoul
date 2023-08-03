# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 16:13:33 by dham              #+#    #+#              #
#    Updated: 2023/04/08 20:24:20 by dham             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -O3 -Wall -Wextra -Werror
TARGET = miniRT
SRCS =	antialiasing.c \
		bright_ctl.c \
		buf_ctl.c \
		color_calculate.c \
		color_ctl.c \
		diffuse.c \
		float_utils.c \
		main.c \
		minirt.c \
		mlx_utils.c \
		multithread_draw.c \
		obj_cone.c \
		obj_cylinder.c \
		obj_plane.c \
		obj_sphere.c \
		parse_ambient.c \
		parse_camera.c \
		parse_light.c \
		parse_object.c \
		parse_object_utils.c \
		parse_utils.c \
		parsing.c \
		ray_utils.c \
		reflection.c \
		texture.c \
		texture_utils.c \
		utils.c \
		vec_utils.c \
		vec_utils2.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBDIR = ./libft
MLXDIR = ./mlx
MLX_LIB = libmlx.dylib

all: $(TARGET)

$(TARGET): $(OBJS)
	$(MAKE) -C$(LIBDIR) all
	$(MAKE) -C$(MLXDIR) all
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBDIR) -lft -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
	ln -s $(MLXDIR)/$(MLX_LIB) .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBDIR) -I$(MLXDIR)

clean:
	$(MAKE) -C $(LIBDIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(LIBDIR)/libft.a
	$(RM) $(TARGET)
	$(RM) ./$(MLX_LIB)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus
