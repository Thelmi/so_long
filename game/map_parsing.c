/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:31:40 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/08 19:17:23 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map_free(char **read, char **read_next, int fd)
{
	int	count;

	count = 0;
	while (*read)
	{
		*read_next = get_next_line(fd);
		count++;
		if (*read_next == NULL)
			break ;
		empty_map(*read_next);
		if (count > 11 && ((t_strchr(*read_next, '\n') == 0
					&& !is_fully_one(*read_next))
				|| (t_strchr(*read_next, '\n') && !is_one(*read_next))))
		{
			write(2, "invalid entries2\n", 17);
			if (*read)
				free(*read);
			if (*read_next)
				free(*read_next);
			exit(1);
		}
		*read = ft_strjoin(*read, *read_next);
		free (*read_next);
	}
}

void	not_fully_one(char *read)
{
	if (!is_fully_one(read))
	{
		write (2, "invalid entries\n", 16);
		free (read);
		exit (1);
	}
}

void	succes_or_fail(t_game game)
{
	if (game.coins == 0 && game.end == 1)
		printf("success\n");
	else
	{
		printf("failure\n");
		exit(1);
	}
}

void	ouch(char **str)
{
	free_arr(str);
	write(2, "invalid entries4\n", 17);
	exit(1);
}

t_game	map_parsing(int fd)
{
	char	*read;
	char	*read_next;
	char	**str;
	t_game	game;

	read = get_next_line(fd);
	empty_map(read);
	read_next = NULL;
	str = NULL;
	game.map = NULL;
	game.copy = NULL;
	not_fully_one(read);
	read_map_free(&read, &read_next, fd);
	str = ft_split(read, '\n');
	if (!valid_letters_count(str, &game))
		ouch(str);
	game.map = str;
	game.copy = ft_split(read, '\n');
	free(read);
	catch_me_if_you_can(&game);
	game.end = 0;
	flood_fill(&game, game.x, game.y);
	if (game.copy)
		free(game.copy);
	succes_or_fail(game);
	return (game);
}
