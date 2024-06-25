/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:36:48 by thelmy            #+#    #+#             */
/*   Updated: 2023/11/18 19:42:33 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	if ((unsigned char) c == '\0')
		return ((char *)(s + i));
	while (i >= 0)
	{
		if ((unsigned char)c == s[i])
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
