/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:40:40 by thelmy            #+#    #+#             */
/*   Updated: 2023/11/27 16:05:45 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlen;

	i = 0;
	needlen = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && len > i)
	{
		if (ft_strncmp(haystack + i, needle, needlen) == 0
			&& needlen + i <= len)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
