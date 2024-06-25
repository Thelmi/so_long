/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:56:40 by thelmy            #+#    #+#             */
/*   Updated: 2023/11/24 15:24:18 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] || (unsigned char)c == '\0')
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
