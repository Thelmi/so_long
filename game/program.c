#include "so_long.h"

void	storing_images(t_game *images)
{
	write(1, "??1", 3);
	char *image_paths[5] = {
		"./images/apple.xpm",
		"./images/exit.xpm",
		"./images/floor.xpm",
		"./images/player.xpm",
		"./images/wall.xpm"
	};
	int i = 0;
	write(1, "??2", 3);
	while (i < 5)
	{
		images->graphics[i].img = mlx_xpm_to_image(images->mlx,&image_paths[i], &(images->graphics[i].img_width), &(images->graphics[i].img_height));
		if (images->graphics[i].img == NULL)
			printf("really?!");
		i++;
	}
	
}
int main (int ac, char **av)
{
	t_game 	*game = NULL;

	parsing(ac, av);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		printf("wt\n");
		return (0);
	}
	write(1, "??\n", 3);

	storing_images(game);
}
	//t_images gallery[5];
	//gallery[0].img = mlx_xpm_to_image(images.mlx,"./images/apple.xpm", &(gallery[0].img_width), &(gallery[0].img_height));
	//gallery[1].img = mlx_xpm_to_image(images.mlx,"./images/exit.xpm", &(images.graphics[1].img_width), &(images.graphics[1].img_height));
	//gallery[2].img = mlx_xpm_to_image(images.mlx,"./images/floor.xpm", &(images.graphics[2].img_width), &(images.graphics[2].img_height));
	//gallery[3].img = mlx_xpm_to_image(images.mlx,"./images/player.xpm", &(images.graphics[3].img_width), &(images.graphics[3].img_height));
	//gallery[4].img = mlx_xpm_to_image(images.mlx,"./images/wall.xpm", &(images.graphics[4].img_width), &(images.graphics[4].img_height));