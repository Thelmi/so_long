/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:36:59 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/23 21:38:06 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define W 13
# define S 1
# define D 2
# define A 0
# define ESC 53

# include "stdlib.h"
# include "fcntl.h"
# include "./minilibx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct images
{
	void	*img;
	int		img_width;
	int		img_height;
}			t_images;

typedef struct node
{
	int			flag;
	int			count;
	int			enemy_counter;
	int			direction;
	int			height;
	int			width;
	char		**map;
	char		**copy;
	char		*read;
	int			x;
	int			y;
	int			enemy_x[200];
	int			enemy_y[200];
	int			end;
	int			player;
	int			key;
	int			exit;
	int			coins;
	int			apple;
	int			*size;
	void		*mlx;
	void		*win;
	int			moves;
	int			z;
	int			fd;
	t_images	graphics[9];
}				t_game;

size_t	t_strlen(char *str);
int		t_strncmp( char *s1, char *s2, size_t n);
int		t_strnstr(char *haystack, char *needle);
t_game	map_parsing(int fd);
t_game	parsing(int ac, char **av);
void	w_key_hook(t_game **game);
void	s_key_hook(t_game **game);
void	a_key_hook(t_game **game);
void	d_key_hook(t_game **game);
void	t_drawer(t_game *game, void *win);
int		valid_letters_count(char **str, t_game *game, char *read, int fd);
char	**free_arr(char **arr);
int		is_fully_one(char *str);
int		is_one(char *str);
int		t_strchr(const char *s, int c);
void	catch_me_if_you_can(t_game *map);
void	flood_fill(t_game *game, int x, int y);
void	empty_map(char *str, char *s, int fd);
void	ouch(char **str, t_game game);
void	no_crash(t_game **game, t_game *image, int i);
void	delete_images(t_game **game, t_game *image, int i);
int		close_window(t_game *game);
int		key_hook(int keycode, t_game *game);
void	bt_drawer(t_game *game, void *win);
void	game_over(t_game **game);
void	unintialized(t_game game);
void	something_is_missing(t_game **game, char **str);
void	b_painter(t_game **game, void *win, int *i, int *j);
void	bt_drawer(t_game *game, void *win);
void	b_storing_images(t_game *images);
void	down_left(t_game **game, int *new_x, int *new_y, int *flag);
void	updater(t_game	**game, int *enemies_counter, int *new_x, int *new_y);
int		enemy(t_game *game);
void	up_right(t_game **game, int *new_x, int *new_y, int *flag);
int		bonus_close_window(t_game *game);
void	bonus_game_character(t_game **game, char **str, int *count_c, int *j);
void	bw_key_hook(t_game **game);
void	bs_key_hook(t_game **game);
void	bd_key_hook(t_game **game);
void	ba_key_hook(t_game **game);
void	bonus_game_character(t_game **game, char **str, int *count_c, int *j);
void	game_character_counters(t_game **game, char **str, int *count_c, int *j);
int		b_key_hook(int keycode, t_game *game);
int		b_valid_letters_count(char **str, t_game *game, char *read, int fd);
void	width_checker(t_game **game, int *flag, int j, char **str);
void	initializer(t_game **game);
t_game	b_map_parsing(int fd);
t_game	b_parsing(int ac, char **av);
void	bye(char *str);
void	not_fully_one(char *read, int fd);
void	read_map_free(char **read, char **read_next, int fd);
void	succes_or_fail(t_game game);
#endif
//-fsanitize=address -g3