/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:36:59 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/25 14:54:19 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(SO_LONG)
#define SO_LONG

#include "stdlib.h"
#include "fcntl.h"
# include "stdio.h"
# include "libft/libft.h"
# include "./libft/get_next_line.h"

size_t	t_strlen(char *str);
int		t_strncmp( char *s1, char *s2, size_t n);
int		t_strnstr(char *haystack, char *needle);
void	map_parsing(int fd);
#endif