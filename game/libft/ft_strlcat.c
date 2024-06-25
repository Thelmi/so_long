/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:37:04 by thelmy            #+#    #+#             */
/*   Updated: 2023/11/27 16:16:19 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	j;

	dlen = ft_strlen(dst);
	j = 0;
	if (!dstsize || dlen > dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[j] && dlen + j < dstsize - 1)
	{
		dst[dlen + j] = src[j];
		j++;
	}
	dst[dlen + j] = '\0';
	return (dlen + ft_strlen(src));
}
