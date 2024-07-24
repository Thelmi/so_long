/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_valid_letters_count.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:46:07 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/24 02:25:58 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bonus_game_character(t_game **game, char **str, int *count_c, int *j)
{
	*j = 0;
	while (str[(*game)->height][(*j)])
	{
		if (str[(*game)->height][(*j)] != '1'
			&& str[(*game)->height][(*j)] != '0'
			&& str[(*game)->height][(*j)] != 'P'
			&& str[(*game)->height][(*j)] != 'E'
			&& str[(*game)->height][(*j)] != 'C'
			&& str[(*game)->height][(*j)] != 'N'
			)
			something_is_missing(game, str);
		if (str[(*game)->height][(*j)] == 'P')
			(*game)->player++;
		if (str[(*game)->height][(*j)] == 'E')
			(*game)->exit++;
		if (str[(*game)->height][(*j)] == 'C')
			(*count_c)++;
		if (str[(*game)->height][(*j)] == 'N')
			(*game)->enemy_counter++;
		(*j)++;
	}
}

int	b_valid_letters_count(char **str, t_game *game, char *read, int fd)
{
	int	count_c;
	int	flag;
	int	j;

	initializer(&game);
	count_c = 0;
	flag = 0;
	game->read = read;
	game->fd = fd;
	while (str[game->height])
	{
		bonus_game_character(&game, str, &count_c, &j);
		width_checker(&game, &flag, j, str);
		game->height++;
	}
	if (game->player != 1 || game->exit != 1 || game->enemy_counter >= 5)
		return (0);
	game->coins = count_c;
	game->apple = count_c;
	if (game->height > 11 || game->width > 20)
	{
		write(2, "map is huge", 11);
		(free_arr(str), free(game->read), close(fd), exit(1));
	}
	return (count_c);
}
