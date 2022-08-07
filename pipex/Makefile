CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = pipex
SRCS = pipex.c parse_exe.c error_ctl.c pipe_utils.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBDIR = ./libft

all: $(TARGET)

$(TARGET): $(OBJS)
	$(MAKE) -C$(LIBDIR) all
	$(CC) $(CFLAGS) -o $@ $^ -I$(LIBDIR) -L$(LIBDIR) -lft

bonus: all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBDIR)

clean:
	$(MAKE) -C $(LIBDIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	$(RM) $(TARGET)

re: 
	make fclean
	make all

.PHONY : all clean fclean re bonus
