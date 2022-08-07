# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dham <dham@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 14:32:15 by dham              #+#    #+#              #
#    Updated: 2022/07/28 11:18:27 by dham             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##제작중 디버깅용 메이크파일 -----

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
SRCS = arg_proc.c arr_sort.c list_proc.c preproc.c push_swap.c \
		sandclock_utils.c sandclock.c sort_stack.c sort2.c sort3.c \
		sort5.c stack_oper.c stack_oper2.c stack_oper3.c utils.c
BONUS_SRCS = arg_proc_bonus.c arr_sort_bonus.c checker_bonus.c \
		checker_utils_bonus.c list_proc_bonus.c stack_oper_bonus.c \
		stack_oper2_bonus.c stack_oper3_bonus.c utils_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -f
LIBDIR = ./libft

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C$(LIBDIR) all
	$(CC) $(CFLAGS) -o $@ $^ -I$(LIBDIR) -L$(LIBDIR) -lft

bonus: 
	make $(NAME)
	make $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(MAKE) -C$(LIBDIR) all
	$(CC) $(CFLAGS) -o $@ $^ -I$(LIBDIR) -L$(LIBDIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBDIR)

clean:
	$(MAKE) -C $(LIBDIR) clean
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: clean
	$(RM) $(LIBDIR)/libft.a
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus
