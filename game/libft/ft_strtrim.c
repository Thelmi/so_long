/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:16:19 by thelmy            #+#    #+#             */
/*   Updated: 2023/11/27 20:11:24 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	int		len;	

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	while (ft_strchr(set, s1[len - 1]))
		len--;
	str = malloc(sizeof(char) * (len - i) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + i, len - i + 1);
	return (str);
}
