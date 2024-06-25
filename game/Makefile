NAME = so_long

LIBFT = ./libft/libft.a

SRC = parsing.c map_parsing.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ := $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

re: fclean all

clean:
	rm -rf $(OBJ) $(OBJB)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

.PHONY: clean fclean all bonus re