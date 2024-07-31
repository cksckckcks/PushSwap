SRCS =		push_swap.c \
			push_swap_allocate.c \
			push_swap_operator.c \
			push_swap_quick_sort.c \
			push_swap_stack.c \
			push_swap_utils.c \
			push_swap_main.c \
			push_swap_error_control.c \
			push_swap_bucket.c

HEADER = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LIB_DIR = libft

OBJS = $(SRCS:.c=.o)

TARGET = push_swap

all: $(TARGET)


$(TARGET): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $@ 


%.o : %.c
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
