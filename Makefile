NAME = push_swap

LIBFT = libft
LIBA = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
RM = rm -f

SRC = arg_check.c \
array_handle.c \
basic_stack.c \
bigger_logic.c \
finder_putter.c \
finder.c \
max.c \
push.c \
reverse_rotate.c \
rotate.c \
smaller_logic.c \
stack_assets.c \
swap.c \
pushswap.c \

all: push_swap

$(NAME): $(SRC) $(LIBFT)/$(LIBA)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT)/$(LIBA) -o push_swap


$(LIBFT)/$(LIBA):
	@$(MAKE) -C $(LIBFT)

clean:
	make -C $(LIBFT) clean

fclean: clean
	make -C $(LIBFT) fclean
	$(RM) push_swap
re: fclean all

.PHONY: all clean fclean re
