CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
NAME = libft.a
BONUSSRCS = $(wildcard ft_lst*.c)
SRCS = $(filter-out $(BONUSSRCS), $(wildcard *.c))
OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)
RM = rm -f

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(BONUSOBJS)
else
	OBJECTS = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

bonus:
	make WITH_BONUS=1 all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	$(RM) $(NAME)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus
