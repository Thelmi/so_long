/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:02:35 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/23 12:15:17 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	down_left(t_game **game, int *new_x, int *new_y, int *flag)
{
	if ((*game)->map[*new_x][*new_y - 1] == '0'
			|| (*game)->map[*new_x][*new_y - 1] == 'P')
	{
		(*new_y)--;
		(*game)->direction = 1;
		if ((*game)->map[*new_x][*new_y] != '0'
			&& (*game)->map[*new_x][*new_y] != 'P')
			*flag = 1;
	}
	else if ((*game)->map[*new_x + 1][*new_y] == '0'
		|| (*game)->map[*new_x + 1][*new_y] == 'P')
	{
		(*new_x)++;
		(*game)->direction = 2;
		if ((*game)->map[*new_x][*new_y] != '0'
			&& (*game)->map[*new_x][*new_y] != 'P')
			*flag = 1;
	}
	else
		*flag = 1;
}

void	updater(t_game	**game, int *enemies_counter, int *new_x, int *new_y)
{
	if ((*game)->map[*new_x][*new_y] == 'P')
	{
		write(1, "Game over\n", 10);
		exit(0);
	}
	(*game)->map[(*game)->enemy_x[*enemies_counter]]
	[(*game)->enemy_y[*enemies_counter]] = '0';
	(*game)->map[*new_x][*new_y] = 'N';
	(*game)->enemy_x[*enemies_counter] = *new_x;
	(*game)->enemy_y[*enemies_counter] = *new_y;
	bt_drawer(*game, (*game)->win);
	(*enemies_counter)++;
	*new_x = (*game)->enemy_x[*enemies_counter];
	*new_y = (*game)->enemy_y[*enemies_counter];
}

int	enemy(t_game *game)
{
	static int	count = 0;
	static int	flag = 0;
	int			enemies_counter;
	int			new_x;
	int			new_y;

	enemies_counter = 0;
	count++;
	if (count < 5000)
		return (0);
	count = 0;
	new_x = game->enemy_x[0];
	new_y = game->enemy_y[0];
	while (game->enemy_x[enemies_counter] != -1)
	{
		if (flag == 0)
			down_left(&game, &new_x, &new_y, &flag);
		else
			up_right(&game, &new_x, &new_y, &flag);
		updater(&game, &enemies_counter, &new_x, &new_y);
	}
	mlx_string_put(game->mlx, game->win, 50, 50, 0xFFFFFFF,
		ft_itoa(game->moves));
	mlx_string_put(game->mlx, game->win, 7, 50, 0xFFFFFFF, "Moves:");
	return (0);
}
