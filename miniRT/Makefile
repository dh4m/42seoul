# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 16:13:33 by dham              #+#    #+#              #
#    Updated: 2023/02/21 16:14:22 by dham             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -O3 ##-Wall -Wextra -Werror
TARGET = fractol
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBDIR = ./libft
MLXDIR = ./mlx

all: $(TARGET)

$(TARGET): $(OBJS)
	$(MAKE) -C$(LIBDIR) all
	$(MAKE) -C$(MLXDIR) all
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBDIR) -lft -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBDIR) -I$(MLXDIR)

clean:
	$(MAKE) -C $(LIBDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBDIR)/libft.a
	$(RM) $(MLXDIR)/libmlx.a
	$(RM) $(TARGET)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus
