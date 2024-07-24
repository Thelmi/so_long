/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:07:48 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/24 16:31:23 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	b_map_parsing(int fd)
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
	if (!b_valid_letters_count(str, &game, read, fd))
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

t_game	b_parsing(int ac, char **av)
{
	int		i;
	int		fd;
	t_game	game;

	fd = 0;
	i = 0;
	if (ac != 2)
		exit(1);
	while (i < ac - 1)
	{
		if (t_strnstr(av[1], ".ber") && ft_strlen(av[1]) > 4)
		{
			fd = open (av[1], O_RDONLY);
			if (fd == -1)
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			game = b_map_parsing(fd);
			close(fd);
		}
		bye(av[1]);
		i++;
	}
	return (game);
}

int	bonus_close_window(t_game *game)
{
	write(1, "Game Over", 1);
	delete_images(NULL, game, 8);
	mlx_destroy_window(game->mlx, game->win);
	free_arr(game->map);
	exit(1);
	return (0);
}