CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
TARGET = libft.a
BONUSSRCS = $(wildcard ft_lst*.c)
SRCS = $(filter-out $(BONUSSRCS), $(wildcard *.c)) \
		get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)
RM = rm -f

ifdef WITH_BONUS
	OBJECTS = $(OBJS) $(BONUSOBJS)
else
	OBJECTS = $(OBJS)
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

bonus:
	make WITH_BONUS=1 all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	$(RM) $(TARGET)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus