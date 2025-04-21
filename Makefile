NAME = pipex
BONUS_NAME = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = pipex.c helpers.c error.c
BONUS_SRC = pipex_bonus.c helpers_bonus.c error_bonus.c list_bonus.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
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
	rm -f $(OBJ) $(BONUS_OBJ)
	make -C libft clean
	make -C printf clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C libft fclean
	make -C printf fclean

re: fclean all

.PHONY: all clean fclean re bonus
