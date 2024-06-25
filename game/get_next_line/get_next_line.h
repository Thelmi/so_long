/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:23:33 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/25 15:19:38 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

void	*ta_memmove(void *dst, const void *src, size_t len);
char	*ta_strchr(const char *s, int c);
size_t	ta_strlen(char *str, int c);
char	*ta_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		free_str(char **str);

#endif