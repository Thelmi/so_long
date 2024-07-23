/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:12:16 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/23 21:28:13 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	catch_him_if_you_can(t_game *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	map->enemy_x[0] = 0;
	map->enemy_y[0] = 0;
	while (map->map[++i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N')
			{
				map->enemy_x[count] = i;
				map->enemy_y[count] = j;
				count++;
			}
			j++;
		}
	}
	map->enemy_x[count] = -1;
	map->enemy_y[count] = -1;
}

void	up_right(t_game **game, int *new_x, int *new_y, int *flag)
{
	if ((*game)->map[*new_x][*new_y + 1] == '0'
		|| (*game)->map[*new_x][*new_y + 1] == 'P')
	{
		(*new_y)++;
		(*game)->direction = 3;
		if ((*game)->map[*new_x][*new_y] != '0'
			&& (*game)->map[*new_x][*new_y] != 'P')
			*flag = 0;
	}
	else if ((*game)->map[*new_x - 1][*new_y] == '0'
		|| (*game)->map[*new_x - 1][*new_y] == 'P')
	{
		(*new_x)--;
		(*game)->direction = 0;
		if ((*game)->map[*new_x][*new_y] != '0'
			&& (*game)->map[*new_x][*new_y] != 'P')
			*flag = 0;
	}
	else
		*flag = 0;
}

t_game	game_engine(int ac, char **av)
{
	t_game	game;
	void	*win;

	win = NULL;
	game = b_parsing(ac, av);
	game.direction = 0;
	game.mlx = mlx_init();
	if (!game.mlx)
		unintialized(game);
	win = mlx_new_window(game.mlx, game.width * 128,
			game.height * 128, "My Game");
	if (!win)
		no_crash(NULL, &game, 0);
	game.win = win;
	b_storing_images(&game);
	bt_drawer(&game, win);
	game.moves = 0;
	game.key = mlx_key_hook(win, b_key_hook, &game);
	if (!game.key)
		no_crash(NULL, &game, 6);
	mlx_hook(game.win, 17, 0L, close_window, &game);
	catch_him_if_you_can(&game);
	mlx_loop_hook(game.mlx, enemy, &game);
	mlx_loop(game.mlx);
	return (game);
}

int	main(int ac, char **av)
{
	t_game	game;

	game = game_engine(ac, av);
}

// try to make moves doesnt flinch
// parse cases
// test and then norminette