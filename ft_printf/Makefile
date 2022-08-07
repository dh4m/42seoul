CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
NAME = libftprintf.a
SRCS = \
	bighex_put.c \
	char_put.c \
	ft_printf.c \
	hex_put.c \
	hex_utils.c \
	integer_put.c \
	integer_utils.c \
	integer_utils2.c \
	parse_utils.c \
	parse.c \
	point_put.c \
	string_put.c \
	string_utils.c \
	unknown_put.c \
	unsign_put.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBDIR = libft

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C$(LIBDIR) all
	cp $(LIBDIR)/libft.a $(NAME)
	$(AR) $(ARFLAGS) $@ $^

bonus: all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBDIR)

clean:
	$(MAKE) -C $(LIBDIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
