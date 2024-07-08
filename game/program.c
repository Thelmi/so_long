/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:21:33 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/08 20:41:49 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	painter(t_game **game, void *win, int *i, int *j)
{
	char	**map;
	int		size;
	int		x;
	int		y;

	map = (*game)->map;
	size = 128;
	x = *j * size;
	y = *i * size;
	if (map[*i][*j] == 'C')
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
				(*game)->graphics[0].img, x, y);
		else if (map[*i][*j] == 'E')
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
				(*game)->graphics[1].img, x, y);
		else if (map[*i][*j] == '0')
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
				(*game)->graphics[2].img, x, y);
		else if (map[*i][*j] == 'P')
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
				(*game)->graphics[3].img, x, y);
	else
		mlx_put_image_to_window((*game)->mlx, win,
			(*game)->graphics[4].img, x, y);
		if (!(*game)->z)
		{
			mlx_destroy_image((*game)->mlx, (*game)->win);
			exit(1);
		}
}

void	t_drawer(t_game *game, void *win)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			painter(&game, win, &i, &j);
			j++;
		}
		i++;
	}
}

void	storing_images(t_game *images)
{
	int		i;
	char	*image_paths[5];

	image_paths[0] = "./images/apple.xpm";
	image_paths[1] = "./images/exit.xpm";
	image_paths[2] = "./images/floor.xpm";
	image_paths[3] = "./images/player.xpm";
	image_paths[4] = "./images/wall.xpm";
	i = 0;
	while (i < 5)
	{
		images->graphics[i].img = mlx_xpm_file_to_image
			(images->mlx, image_paths[i],
				&(images->graphics[i].img_width),
				&(images->graphics[i].img_height));
		if (!images->graphics[i].img)
		{
			printf("really?!");
			mlx_destroy_image(images->mlx, images->win);
			exit(1);
		}
		i++;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == W && game->map[game->x - 1][game -> y] != '1')
		w_key_hook(&game);
	if (keycode == S && game->map[game->x + 1][game -> y] != '1')
		s_key_hook(&game);
	if (keycode == D && game->map[game->x][game -> y + 1] != '1')
		d_key_hook(&game);
	if (keycode == A && game->map[game->x][game -> y - 1] != '1')
		a_key_hook(&game);
	if (keycode == ESC)
	{
		mlx_destroy_image(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	void	*win;
	
	win = NULL;
	game = parsing(ac, av);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		printf("unintialized\n");
		exit(1);
	}
	win = mlx_new_window(game.mlx, game.width * 128,
			game.height * 128, "My Game");
	if(!win)
	{
		printf("window crashed\n");
		exit(1);
	}
	game.win = win;
	storing_images(&game);
	t_drawer(&game, win);
	game.moves = 0;
	game.key = mlx_key_hook(win, key_hook, &game);
	if (!game.key)
	{
		printf("really?!");
		mlx_destroy_image(game.mlx, game.win);
		exit(1);
	}
	mlx_loop(game.mlx);
}

// protection of the functions
// memmory management