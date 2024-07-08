NAME = so_long

LIBFT = ./libft/libft.a

MINILBX = minilibx/libmlx.a

SRC = program.c cases.c key_hooks.c valid_letters_count.c map_parsing_helpers.c parsing.c map_parsing.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ := $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iminilibx -Ilibft 
#LDFLAGS = -fsanitize=address -g

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(MINILBX) $(OBJ)
	cc $(OBJ) libft/libft.a -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	make -C ./libft

$(MINILBX):
	make -C ./minilibx

re: fclean all

clean:
	rm -rf $(OBJ) $(OBJB)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

.PHONY: clean fclean all bonus re
