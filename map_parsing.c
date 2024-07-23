/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:31:40 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/23 23:10:36 by thelmy           ###   ########.fr       */
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
		empty_map(*read_next, *read, fd);
		if (count > 11 || ((t_strchr(*read_next, '\n') == 0
					&& !is_fully_one(*read_next))
				|| (t_strchr(*read_next, '\n') && !is_one(*read_next))))
		{
			write(2, "invalid map\n", 12);
			if (*read)
				free(*read);
			if (*read_next)
				free(*read_next);
			close(fd);
			exit(1);
		}
		*read = ft_strjoin(*read, *read_next);
		free (*read_next);
	}
}

void	not_fully_one(char *read, int fd)
{
	if (!is_fully_one(read))
	{
		write (2, "not valid border\n", 16);
		free (read);
		close(fd);
		exit (1);
	}
}

void	succes_or_fail(t_game game)
{
	if (game.coins == 0 && game.end == 1)
		write(1,"success\n", 8);
	else
	{
		write(1, "failure\n", 8);
		free_arr(game.map);
		close(game.fd);
		exit(1);
	}
}

void	ouch(char **str, t_game game)
{
	free_arr(str);
	free(game.read);
	write(2, "invalid\n", 8);
	close(game.fd);
	exit(1);
}

t_game	map_parsing(int fd)
{
	char	*read;
	char	*read_next;
	char	**str;
	t_game	game;

	read = get_next_line(fd);
	empty_map(read, NULL, fd);
	read_next = NULL;
	game.map = NULL;
	game.copy = NULL;
	not_fully_one(read, fd);
	read_map_free(&read, &read_next, fd);
	str = ft_split(read, '\n');
	if (!valid_letters_count(str, &game, read, fd))
		ouch(str, game);
	game.map = str;
	game.copy = ft_split(read, '\n');
	free(read);
	catch_me_if_you_can(&game);
	game.end = 0;
	flood_fill(&game, game.x, game.y);
	if (game.copy)
		free_arr(game.copy);
	succes_or_fail(game);
	return (game);
}
