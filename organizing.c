/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:04:46 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/23 21:15:08 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	something_is_missing(t_game **game, char **str)
{
	free_arr(str);
	free((*game)->read);
	write(2, "input invalid", 13);
	close((*game)->fd);
	exit(1);
}
