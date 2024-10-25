/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:36:01 by thelmy            #+#    #+#             */
/*   Updated: 2024/08/01 12:05:07 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	t_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	t_strncmp( char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] && s2[i]) && (s1[i] == s2[i] && i < n - 1))
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	t_strnstr(char *haystack, char *needle)
{
	size_t	i;
	size_t	needlen;
	size_t	len;

	i = 0;
	len = ft_strlen(haystack);
	needlen = t_strlen(needle);
	if (!*needle)
		return (0);
	while (i < needlen)
	{
		if (t_strncmp(&haystack[len - 4], needle, needlen) == 0
			&& haystack[len - 5] != '/')
			return (1);
		i++;
	}
	if (haystack[len - 5] == '/')
		return (0);
	return (0);
}

void	bye(char *str)
{
	if (!(t_strnstr(str, ".ber") && t_strlen(str) > 4))
	{
		write(1, "not funny\n", 10);
		exit (1);
	}
}

t_game	parsing(int ac, char **av)
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
			game = map_parsing(fd);
			close(fd);
		}
		bye(av[1]);
		i++;
	}
	return (game);
}
