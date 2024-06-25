/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:31:40 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/25 14:46:49 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_parsing(int fd)
{
	char *read = get_next_line(fd);
	while (read)
	{
		printf("%s",read);
		read = get_next_line(fd);
	}
	
}