/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:36:59 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/28 14:28:08 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(SO_LONG)
#define SO_LONG

#include "stdlib.h"
#include "fcntl.h"
# include "stdio.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct node
{
	int		height;
	int		width;
	char	**map;
	char	**copy;
	int		x;
	int		y;
	int		end;
	int		coins;
}			t_game;

size_t	t_strlen(char *str);
int		t_strncmp( char *s1, char *s2, size_t n);
int		t_strnstr(char *haystack, char *needle);
char	**map_parsing(int fd);
#endif
