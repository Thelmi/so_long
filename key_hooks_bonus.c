/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:29:48 by thelmy            #+#    #+#             */
/*   Updated: 2024/08/01 12:03:32 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bw_key_hook(t_game **game)
{
	if ((*game)->map[(*game)->x - 1][(*game)-> y] == 'C')
		(*game)->apple--;
	if (((*game)->map[(*game)->x - 1][(*game)-> y] == 'E'
		&& (*game)->apple == 0)
		|| ((*game)->map[(*game)->x - 1][(*game)-> y] == 'N'))
	{
		mlx_destroy_window((*game)->mlx, (*game)->win);
		delete_images(game, NULL, 4);
		if ((*game)->map[(*game)->x - 1][(*game)-> y] == 'N')
			game_over(game);
		free_arr((*game)->map);
		write(1, "Congrats u did it", 17);
		exit(0);
	}
	else if ((*game)->map[(*game)->x - 1][(*game)-> y] != 'E')
	{
		(*game)->map[(*game)->x][(*game)->y] = '0';
		(*game)->map[(*game)->x - 1][(*game)->y] = 'P';
		(*game)->x--;
		bt_drawer((*game), (*game)->win);
		(*game)->moves++;
		write(1, "Moves: ", 7);
		ft_putnbr_fd((*game)->moves, 1);
		write(1, "\n", 1);
	}
}

void	bs_key_hook(t_game **game)
{
	if ((*game)->map[(*game)->x + 1][(*game)-> y] == 'C')
		(*game)->apple--;
	if (((*game)->map[(*game)->x + 1][(*game)-> y] == 'E'
		&& (*game)->apple == 0)
		|| (*game)->map[(*game)->x + 1][(*game)-> y] == 'N')
	{
		mlx_destroy_window((*game)->mlx, (*game)->win);
		delete_images(game, NULL, 4);
		if ((*game)->map[(*game)->x + 1][(*game)-> y] == 'N')
			game_over(game);
		free_arr((*game)->map);
		write(1, "Congrats u did it", 17);
		exit(0);
	}
	else if ((*game)->map[(*game)->x + 1][(*game)-> y] != 'E')
	{
		(*game)->map[(*game)->x][(*game)->y] = '0';
		(*game)->map[(*game)->x + 1][(*game)->y] = 'P';
		(*game)->x++;
		bt_drawer((*game), (*game)->win);
		(*game)->moves++;
		write(1, "Moves: ", 7);
		ft_putnbr_fd((*game)->moves, 1);
		write(1, "\n", 1);
	}
}

void	bd_key_hook(t_game **game)
{
	if ((*game)->map[(*game)->x][(*game)-> y + 1] == 'C')
		(*game)->apple--;
	if (((*game)->map[(*game)->x][(*game)-> y + 1] == 'E'
		&& (*game)->apple == 0)
		|| (*game)->map[(*game)->x][(*game)-> y + 1] == 'N')
	{
		mlx_destroy_window((*game)->mlx, (*game)->win);
		delete_images(game, NULL, 4);
		if ((*game)->map[(*game)->x][(*game)-> y + 1] == 'N')
			game_over(game);
		free_arr((*game)->map);
		write(1, "Congrats u did it", 17);
		exit(0);
	}
	else if ((*game)->map[(*game)->x][(*game)-> y + 1] != 'E')
	{
		(*game)->map[(*game)->x][(*game)->y] = '0';
		(*game)->map[(*game)->x][(*game)->y + 1] = 'P';
		(*game)->y++;
		bt_drawer((*game), (*game)->win);
		(*game)->moves++;
		write(1, "Moves: ", 7);
		ft_putnbr_fd((*game)->moves, 1);
		write(1, "\n", 1);
	}
}

void	ba_key_hook(t_game **game)
{
	if ((*game)->map[(*game)->x][(*game)-> y - 1] == 'C')
		(*game)->apple--;
	if (((*game)->map[(*game)->x][(*game)-> y - 1] == 'E'
		&& (*game)->apple == 0)
		|| (*game)->map[(*game)->x][(*game)-> y - 1] == 'N')
	{
		mlx_destroy_window((*game)->mlx, (*game)->win);
		delete_images(game, NULL, 4);
		if ((*game)->map[(*game)->x][(*game)-> y - 1] == 'N')
			game_over(game);
		free_arr((*game)->map);
		write(1, "Congrats u did it", 17);
		exit(0);
	}
	else if ((*game)->map[(*game)->x][(*game)-> y - 1] != 'E')
	{
		(*game)->map[(*game)->x][(*game)->y] = '0';
		(*game)->map[(*game)->x][(*game)->y - 1] = 'P';
		(*game)->y--;
		bt_drawer((*game), (*game)->win);
		(*game)->moves++;
		write(1, "Moves: ", 7);
		ft_putnbr_fd((*game)->moves, 1);
		write(1, "\n", 1);
	}
}

void	empty_map(char *str, char *s, int fd)
{
	if (!str || str[0] == '\n')
	{
		write(2, "empty map\n", 10);
		if (str)
			free(str);
		if (s)
			free(s);
		close(fd);
		exit(1);
	}
}
