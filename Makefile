NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = pipex.c helpers.c error.c child.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf

clean:
	rm -f $(OBJ) 
	make -C libft clean
	make -C printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C printf fclean

re: fclean all

.PHONY: all clean fclean re bonus
