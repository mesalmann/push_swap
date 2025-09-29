NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	main.c \
		build_stack.c \
		error_util.c \
		ops_push.c \
		ops_rotate.c \
		ops_reverse_rotate.c \
		ops_swap.c

OBJS = $(SRCS:.c=.o)

HDRS = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
