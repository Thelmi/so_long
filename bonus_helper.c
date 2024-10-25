/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:27:00 by thelmy            #+#    #+#             */
/*   Updated: 2024/08/01 11:59:30 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	**_pointer(t_game **game, void *win, int *i, int *j)
{
	char	**map;
	int		x;
	int		y;

	y = *i * 128;
	x = *j * 128;
	map = (*game)->map;
	if (map[*i][*j] == 'N' && (*game)->direction == 1)
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
				(*game)->graphics[5].img, x, y);
	else if (map[*i][*j] == 'N' && (*game)->direction == 2)
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
				(*game)->graphics[6].img, x, y);
	else if (map[*i][*j] == 'N' && (*game)->direction == 3)
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
				(*game)->graphics[7].img, x, y);
	else if (map[*i][*j] == 'N' && (*game)->direction == 0)
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
				(*game)->graphics[8].img, x, y);
	return (game);
}

void	b_painter(t_game **game, void *win, int *i, int *j)
{
	char	**map;
	int		x;
	int		y;

	map = (*game)->map;
	x = *j * 128;
	y = *i * 128;
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
	else if (map[*i][*j] == '1')
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
				(*game)->graphics[4].img, x, y);
	game = _pointer(game, win, i, j);
	if (!(*game)->z)
		no_crash(game, NULL, 5);
}

void	bt_drawer(t_game *game, void *win)
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
			b_painter(&game, win, &i, &j);
			j++;
		}
		i++;
	}
}

void	b_storing_images(t_game *images)
{
	int		i;
	char	*image_paths[9];

	image_paths[0] = "./images/apple.xpm";
	image_paths[1] = "./images/exit.xpm";
	image_paths[2] = "./images/floor.xpm";
	image_paths[3] = "./images/player.xpm";
	image_paths[4] = "./images/wall.xpm";
	image_paths[5] = "./images/roachleft.xpm";
	image_paths[6] = "./images/roachdown.xpm";
	image_paths[7] = "./images/roachright.xpm";
	image_paths[8] = "./images/roachup.xpm";
	i = 0;
	while (i < 9)
	{
		images->graphics[i].img = mlx_xpm_file_to_image(images->mlx,
				image_paths[i],
				&(images->graphics[i].img_width),
				&(images->graphics[i].img_height));
		if (!images->graphics[i].img)
			no_crash(NULL, images, i - 1);
		i++;
	}
}

int	b_key_hook(int keycode, t_game *game)
{
	if (keycode == W && game->map[game->x - 1][game -> y] != '1')
		bw_key_hook(&game);
	if (keycode == S && game->map[game->x + 1][game -> y] != '1')
		bs_key_hook(&game);
	if (keycode == D && game->map[game->x][game -> y + 1] != '1')
		bd_key_hook(&game);
	if (keycode == A && game->map[game->x][game -> y - 1] != '1')
		ba_key_hook(&game);
	if (keycode == ESC)
		bonus_close_window(game);
	return (0);
}
