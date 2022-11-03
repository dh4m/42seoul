# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 13:48:24 by dham              #+#    #+#              #
#    Updated: 2022/11/03 15:35:30 by dham             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g #-Wall -Wextra -Werror
NAME = minishell
SRCS = $(wildcard *.c) $(wildcard builtin/*.c) $(wildcard signal/*.c)
OBJS = $(SRCS:.c=.o)
RM = rm -f

LIBFT_DIR = ./libft
RDLN_DIR = ${HOME}/.brew/opt/readline
# RDLN_DIR = /opt/homebrew/opt/readline

LIBFT_COMPILE = -I$(LIBFT_DIR)
LIBFT_LINKING = -L$(LIBFT_DIR) -lft

RDLN_COMPILE = -I$(RDLN_DIR)/include
RDLN_LINKING = -L$(RDLN_DIR)/lib -lreadline

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C$(LIBFT_DIR) all
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_LINKING) $(RDLN_LINKING)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBFT_COMPILE) $(RDLN_COMPILE)

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