/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:36:59 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/30 15:42:29 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(SO_LONG)
#define SO_LONG

#include "stdlib.h"
#include "fcntl.h"
# include "stdio.h"
#include "./minilibx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct images
{
	void	*img;
	int		img_width;
	int		img_height;
}			t_images;

typedef struct node
{
	int			height;
	int			width;
	char		**map;
	char		**copy;
	int			x;
	int			y;
	int			end;
	int			coins;
	void		*mlx;
	t_images	graphics[5];
}				t_game;

size_t	t_strlen(char *str);
int		t_strncmp( char *s1, char *s2, size_t n);
int		t_strnstr(char *haystack, char *needle);
char	**map_parsing(int fd);
void	parsing(int ac, char **av);
#endif
