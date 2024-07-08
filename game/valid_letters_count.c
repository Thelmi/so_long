/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_letters_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:57:51 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/08 17:16:08 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	initializer(t_game **game)
{
	(*game)->height = 0;
	(*game)->width = 0;
	(*game)->coins = 0;
	(*game)->player = 0;
	(*game)->exit = 0;
	(*game)->apple = 0;
}

void	game_character_counters(t_game **game, char **str, int *count_c, int *j)
{
	*j = 0;
	while (str[(*game)->height][(*j)])
	{
		if (str[(*game)->height][(*j)] != '1'
			&& str[(*game)->height][(*j)] != '0'
			&& str[(*game)->height][(*j)] != 'P'
			&& str[(*game)->height][(*j)] != 'E'
			&& str[(*game)->height][(*j)] != 'C')
		{
			free_arr(str);
			write(2, "invalid entries4\n", 17);
			exit(1);
		}
		if (str[(*game)->height][(*j)] == 'P')
			(*game)->player++;
		if (str[(*game)->height][(*j)] == 'E')
			(*game)->exit++;
		if (str[(*game)->height][(*j)] == 'C')
			(*count_c)++;
		(*j)++;
	}
}

void	width_checker(t_game **game, int *flag, int j, char **str)
{
	if (0 < j)
	{
		if (!(*game)->width && !*flag)
		{
			(*game)->width = j;
			*flag = 1;
		}
		if ((*game)->width != j)
		{
			free_arr(str);
			write(2, "invalid entries4\n", 17);
			exit(1);
		}
	}
}

int	valid_letters_count(char **str, t_game *game)
{
	int	count_c;
	int	flag;
	int	j;

	initializer(&game);
	count_c = 0;
	flag = 0;
	while (str[game->height])
	{
		game_character_counters(&game, str, &count_c, &j);
		width_checker(&game, &flag, j, str);
		game->height++;
	}
	if (game->player != 1 || game->exit != 1)
		return (0);
	game->coins = count_c;
	game->apple = count_c;
	if (game->height > 11 || game->width > 20)
	{
		printf("error");
		free_arr(str);
		exit(1);
	}
	return (count_c);
}
