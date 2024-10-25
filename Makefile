NAME = so_long

BNAME = so_long_b

LIBFT = ./libft/libft.a

MINILBX = minilibx/libmlx.a

SRC = program.c organizing.c cases.c key_hooks.c valid_letters_count.c map_parsing_helpers.c parsing.c map_parsing.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

BSRC = so_long_bonus.c b_parsing.c enemy.c key_hooks_bonus.c bonus_valid_letters_count.c valid_letters_count.c bonus_helper.c organizing.c cases.c map_parsing_helpers.c parsing.c map_parsing.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ := $(SRC:.c=.o)

OBJB := $(BSRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Iminilibx -Ilibft

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(MINILBX) $(OBJ)
	cc $(OBJ) libft/libft.a -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

$(LIBFT):
	make -C ./libft

$(MINILBX):
	make -C ./minilibx

bonus: $(BNAME)

$(BNAME): $(LIBFT) $(MINILBX) $(OBJB)
	cc $(OBJB) libft/libft.a -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(BNAME) 

re: fclean all

clean:
	rm -rf $(OBJ) $(OBJB)
	make clean -C ./libft
	make clean -C ./minilibx
fclean: clean
	rm -rf $(NAME) $(BNAME)
	make fclean -C ./libft

.PHONY: clean fclean all bonus re
