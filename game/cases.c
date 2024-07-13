/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:06:34 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/13 21:05:48 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_images(t_game **game, t_game *image, int i)
{
	if (image != NULL)
	{
		while (i >= 0)
			mlx_destroy_image(image->mlx, image->graphics[i--].img);
	}
	else
	{
		while (i >= 0)
			mlx_destroy_image((*game)->mlx, (*game)->graphics[i--].img);
	}
}
void	no_crash(t_game **game, t_game *image, int i)
{
	if (image != NULL)
	{
		write(2, "execution failed", 16);
		if(image->win)
			mlx_destroy_window(image->mlx, image->win);
		if(image->graphics[0].img)
			delete_images(NULL, image, i);
		free_arr(image->map);
		exit(1);
	}
	else
	{
		write(2, "execution failed", 16);
		if ((*game)->win)
			mlx_destroy_window((*game)->mlx, (*game)->win);
		if((*game)->graphics[0].img)
			delete_images(game, NULL, i);
		free_arr((*game)->map);
		exit(1);
	}
}
int	close_window(t_game *game)
{
	delete_images(NULL, game, 4);
	mlx_destroy_window(game->mlx, game->win);
	free_arr(game->map);
	exit(1);
	return 0;
}

