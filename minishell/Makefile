# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 13:48:24 by dham              #+#    #+#              #
#    Updated: 2023/01/23 20:11:18 by dham             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror #-fsanitize=address 
NAME = minishell
SRCS = $(wildcard *.c) $(wildcard builtin/*.c) $(wildcard signal/*.c) $(wildcard get_next_line/*.c) $(wildcard ascii/*.c)
OBJS = $(SRCS:.c=.o)
RM = rm -f

LIBFT_DIR = ./libft

LIBFT_COMPILE = -I$(LIBFT_DIR)
LIBFT_LINKING = -L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C$(LIBFT_DIR) all
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_LINKING) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBFT_COMPILE)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT_DIR)/libft.a
	$(RM) $(NAME)

re: 
	make fclean
	make all

.PHONY : all clean fclean re
