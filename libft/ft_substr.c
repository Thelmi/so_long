/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:32:29 by thelmy            #+#    #+#             */
/*   Updated: 2023/11/27 16:15:16 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
	{
		str = malloc((sizeof(char) * (ft_strlen(s) - start + 1)));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s + start, ft_strlen(s) - start + 1);
	}
	else
	{
		str = malloc((sizeof(char) * len + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s + start, len + 1);
	}
	return (str);
}
