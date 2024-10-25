/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:16:30 by thelmy            #+#    #+#             */
/*   Updated: 2023/11/27 20:12:19 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char *str, char sep)
{
	int	i;
	int	word;

	word = 0;
	i = 1;
	if (!*str)
		return (0);
	while (str[i])
	{
		if ((str[i] == sep && str[i - 1] != sep)
			|| (str[i] != sep && str[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**getwords(char **arr, char *s, char c, int word)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i] && k < word)
	{
		j = 0;
		if (s[i] && s[i] != c)
		{
			while (s[i + j] && s[i + j] != c)
				j++;
			arr[k] = ft_substr(s, i, j);
			if (!arr[k])
				return (free_arr(arr));
			k++;
			i += j;
		}
		else
			i++;
	}
	arr[k] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word;

	if (!s)
		return (NULL);
	word = wordcount((char *)s, c);
	arr = malloc(sizeof(char *) * (word + 1));
	if (!arr)
		return (NULL);
	return (getwords(arr, (char *)s, c, word));
}
