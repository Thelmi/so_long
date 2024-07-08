/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:19:07 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/06 22:47:55 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_fully_one(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
		{
			if (str[i] == '\n')
				break ;
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_one(char *str)
{
	int	len;

	len = ft_strlen(str) - 2;
	if (str[0] == '1' && str[len] == '1')
		return (1);
	return (0);
}

int	t_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return (1);
		i++;
	}
	return (0);
}

void	catch_me_if_you_can(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->x = 0;
	map->y = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->x = i;
				map->y = j;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->height || y >= game->width)
		return ;
	if (game->copy[x][y] == '1')
		return ;
	if (game->copy[x][y] == 'C')
		game->coins--;
	if (game->copy[x][y] == 'E')
	{
		game->end = 1;
		return ;
	}
	game->copy[x][y] = '1';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}
