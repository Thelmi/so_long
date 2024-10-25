/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:12:38 by thelmy            #+#    #+#             */
/*   Updated: 2023/11/27 21:24:59 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*destin;
	char const	*sourc;

	if (!dst && !src)
		return (NULL);
	destin = (char *)dst;
	sourc = (char *)src;
	i = 0;
	while (i < n)
	{
		destin[i] = sourc[i];
		i++;
	}
	return (dst);
}
