/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:38:39 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/06 22:47:11 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_key_hook(t_game **game)
{
	if ((*game)->map[(*game)->x - 1][(*game)-> y] == 'C')
		(*game)->apple--;
	if ((*game)->map[(*game)->x - 1][(*game)-> y] == 'E' && (*game)->apple == 0)
	{
		mlx_destroy_window((*game)->mlx, (*game)->win);
		exit(0);
	}
	else if ((*game)->map[(*game)->x - 1][(*game)-> y] != 'E')
	{
		(*game)->map[(*game)->x][(*game)->y] = '0';
		(*game)->map[(*game)->x - 1][(*game)->y] = 'P';
		(*game)->x--;
		t_drawer((*game), (*game)->win);
		(*game)->moves++;
		printf("moves: %d\n", (*game)->moves);
	}
}

void	s_key_hook(t_game **game)
{
	if ((*game)->map[(*game)->x + 1][(*game)-> y] == 'C')
		(*game)->apple--;
	if ((*game)->map[(*game)->x + 1][(*game)-> y] == 'E' && (*game)->apple == 0)
	{
		mlx_destroy_window((*game)->mlx, (*game)->win);
		exit(0);
	}
	else if ((*game)->map[(*game)->x + 1][(*game)-> y] != 'E')
	{
		(*game)->map[(*game)->x][(*game)->y] = '0';
		(*game)->map[(*game)->x + 1][(*game)->y] = 'P';
		(*game)->x++;
		t_drawer((*game), (*game)->win);
		(*game)->moves++;
		printf("moves: %d\n", (*game)->moves);
	}
}

void	d_key_hook(t_game **game)
{
	if ((*game)->map[(*game)->x][(*game)-> y + 1] == 'C')
		(*game)->apple--;
	if ((*game)->map[(*game)->x][(*game)-> y + 1] == 'E' && (*game)->apple == 0)
	{
		mlx_destroy_window((*game)->mlx, (*game)->win);
		exit(0);
	}
	else if ((*game)->map[(*game)->x][(*game)-> y + 1] != 'E')
	{
		(*game)->map[(*game)->x][(*game)->y] = '0';
		(*game)->map[(*game)->x][(*game)->y + 1] = 'P';
		(*game)->y++;
		t_drawer((*game), (*game)->win);
		(*game)->moves++;
		printf("moves: %d\n", (*game)->moves);
	}
}

void	a_key_hook(t_game **game)
{
	if ((*game)->map[(*game)->x][(*game)-> y -1] == 'C')
		(*game)->apple--;
	if ((*game)->map[(*game)->x][(*game)-> y - 1] == 'E' && (*game)->apple == 0)
	{
		mlx_destroy_window((*game)->mlx, (*game)->win);
		exit(0);
	}
	else if ((*game)->map[(*game)->x][(*game)-> y - 1] != 'E')
	{
		(*game)->map[(*game)->x][(*game)->y] = '0';
		(*game)->map[(*game)->x][(*game)->y - 1] = 'P';
		(*game)->y--;
		t_drawer((*game), (*game)->win);
		(*game)->moves++;
		printf("moves: %d\n", (*game)->moves);
	}
}

void	empty_map(char *str)
{
	if (!str || str[0] == '\n')
	{
		printf("eww what is this");
		exit(1);
	}
}
