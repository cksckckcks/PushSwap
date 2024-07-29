SRCS =		push_swap.c \
			push_swap_allocate.c \
			push_swap_operator.c \
			push_swap_quick_sort.c \
			push_swap_stack.c \
			push_swap_utils.c

HEADER = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

TARGET = push_swap

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
