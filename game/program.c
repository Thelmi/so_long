/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:21:33 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/05 14:34:23 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
	
void	two_printer(char **str)
{
	int i = 0;

	while (str[i])
		printf("%s\n", str[i++]);
}

void t_drawer(t_game *game, void *win)
{
    char **map = game->map;
    int size = 128; 
    int i;
	int j;
	int x;
	int y;
	
    i = 0;
	j = 0;
	//two_printer(map);
    while (map[i])
    {
		j = 0;
        while (map[i][j])
        {
			x = j * size;
       		y = i * size;
            if (map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx, win, game->graphics[0].img, x, y);
        	else if (map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx, win, game->graphics[1].img, x, y);
            else if (map[i][j] == '0')
                mlx_put_image_to_window(game->mlx, win, game->graphics[2].img, x, y);
            else if(map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx, win, game->graphics[3].img, x, y);
            else
                mlx_put_image_to_window(game->mlx, win, game->graphics[4].img, x, y);
            j++;
        }
        i++;
    }
}

void	storing_images(t_game *images)
{
	char *image_paths[5] = {
		"./images/apple.xpm",
		"./images/exit.xpm",
		"./images/floor.xpm",
		"./images/player.xpm",
		"./images/wall.xpm"
	};
	int i = 0;
	while (i < 5)
	{
		images->graphics[i].img = mlx_xpm_file_to_image(images->mlx,image_paths[i], &(images->graphics[i].img_width), &(images->graphics[i].img_height));
		if (images->graphics[i].img == NULL)
			printf("really?!");
		i++;
	}
}
int	key_hook(int keycode, t_game *game)
{
	if (keycode == W && game->map[game->x - 1][game -> y] != '1')
	{
		printf("%d\n",game->apple);
		if (game->map[game->x - 1][game -> y] == 'C')
			game->apple--;
		if (game->map[game->x - 1][game -> y] == 'E' && game->apple == 0)
		{
			mlx_destroy_window(game->mlx, game->win);
			exit(0);
		}
		else if(game->map[game->x - 1][game -> y] != 'E')
		{
			game->map[game->x][game->y] = '0';
			game->map[game->x - 1][game->y] = 'P';
			game->x--;
			t_drawer(game, game->win);
			game->moves++;
			printf("moves: %d\n", game->moves);
		}
	}
	if (keycode == S && game->map[game->x + 1][game -> y] != '1')
	{
		printf("%d\n",game->apple);
		if (game->map[game->x + 1][game -> y] == 'C')
			game->apple--;
		if (game->map[game->x + 1][game -> y] == 'E' && game->apple == 0)
		{
			mlx_destroy_window(game->mlx, game->win);
			exit(0);
		}
		else if(game->map[game->x + 1][game -> y] != 'E')
		{
			game->map[game->x][game->y] = '0';
			game->map[game->x + 1][game->y] = 'P';
			game->x++;
			t_drawer(game, game->win);
			game->moves++;
			printf("moves: %d\n", game->moves);
		}
	}
	if (keycode == D && game->map[game->x][game -> y + 1] != '1')
	{
		printf("%d\n",game->apple);
		if (game->map[game->x][game -> y + 1] == 'C')
			game->apple--;
		if (game->map[game->x][game -> y + 1] == 'E' && game->apple == 0)
		{
			mlx_destroy_window(game->mlx, game->win);
			exit(0);
		}
		else if(game->map[game->x][game -> y + 1] != 'E')
		{
			game->map[game->x][game->y] = '0';
			game->map[game->x][game->y + 1] = 'P';
			game->y++;
			t_drawer(game, game->win);
			game->moves++;
			printf("moves: %d\n", game->moves);
		}
	}
	if (keycode == A && game->map[game->x][game -> y - 1] != '1')
	{
		printf("%d\n",game->apple);
		if (game->map[game->x][game -> y -1] == 'C')
			game->apple--;
		if (game->map[game->x][game -> y - 1] == 'E' && game->apple == 0)
		{
			mlx_destroy_window(game->mlx, game->win);
			exit(0);
		}
		else if(game->map[game->x][game -> y - 1] != 'E')
		{
			game->map[game->x][game->y] = '0';
			game->map[game->x][game->y - 1] = 'P';
			game->y--;
			t_drawer(game, game->win);
			game->moves++;
			printf("moves: %d\n", game->moves);
		}
	}
	return (0);
}
int main (int ac, char **av)
{
	t_game	game;

	void	*win  = NULL;
	
	(void)ac;
	(void)av;
	game = parsing(ac, av);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		printf("error\n");
		return (0);
	}
	printf ("%d\n",game.width);
	win = mlx_new_window(game.mlx, game.width * 128,
			game.height * 128, "My Game");
	game.win = win;
	storing_images(&game);
	t_drawer(&game, win);
	game.moves = 0;
	mlx_key_hook(win, key_hook, &game);
	mlx_loop(game.mlx);
}
