/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:31:40 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/06 14:25:53 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_letters_count(char **str, t_game *game)
{
	int	i;
	int	j;
	int	count_p;
	int	count_e;
	int	count_c;
	int	flag;

	i = 0;
	j = 0;
	count_p = 0;
	count_e = 0;
	count_c = 0;
	game ->width = 0;
	game ->height = 0;
	flag = 0;
	game ->coins = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '1' && str[i][j] != '0'
				&& str[i][j] != 'P' && str[i][j] != 'E' && str[i][j] != 'C')
				return (0);
			if (str[i][j] == 'P')
				count_p++;
			if (str[i][j] == 'E')
				count_e++;
			if (str[i][j] == 'C')
				count_c ++;
			j++;
		}
		if (0 < j)
		{
			if (!game->width && !flag)
			{
				game->width = j;
				flag = 1;
			}
			if (game->width != j)
				return (0);
		}
		i++;
	}
	game->height = i;
	if (count_p != 1 || count_e != 1)
		return (0);
	game->coins = count_c;
	game->apple = count_c;
	return (count_c);
}

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

	len = ft_strlen(str) - 1;
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

char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
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

t_game	map_parsing(int fd)
{
	char	*read;
	char	*read_next;
	char	**str;
	t_game	game;

	read = get_next_line(fd);
	read_next = NULL;
	str = NULL;
	game.map = NULL;
	game.copy = NULL;
	if (!is_fully_one(read))
	{
		write (2, "invalid entries\n", 16);
		free (read);
		exit (1);
	}
	while (read)
	{
		read_next = get_next_line(fd);
		if (read_next == NULL)
			break ;
		if ((t_strchr(read_next, '\n') == 0
				&&!is_fully_one(read_next))
			|| (t_strchr(read_next, '\n') && is_one(read_next)))
		{
			write(2, "invalid entries2\n", 17);
			free(read);
			exit(1);
		}
		read = ft_strjoin(read, read_next);
		free (read_next);
	}
	str = ft_split(read, '\n');
	if (!valid_letters_count(str, &game))
	{
		free_arr(str);
		write(2, "invalid entries4\n", 17);
		exit(1);
	}
	game.map = str;
	game.copy = ft_split(read, '\n');
	catch_me_if_you_can(&game);
	game.end = 0;
	flood_fill(&game, game.x, game.y);
	if (game.coins == 0 && game.end == 1)
		printf("success\n");
	else
	{
		printf("failure\n");
		exit(1);
	}
	free (read);
	return (game);
}
