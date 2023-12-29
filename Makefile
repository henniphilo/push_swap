NAME = push_swap

LIBFT = libft
LIBA = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
RM = rm -f

SRC = *.c \

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
