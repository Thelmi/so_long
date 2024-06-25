NAME = so_long

LIBFT = ./libft/libft.a

SRC = parsing.c  map_parsing.c \

OBJ := $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C ./libft

re: fclean all

clean:
	rm -rf $(OBJ) $(OBJB)
	make clean -C ./libft
	make clean -C ./ft_printf

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	make fclean -C ./libft
	make fclean -C ./ft_printf

.PHONY: clean fclean all bonus re