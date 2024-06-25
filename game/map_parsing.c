/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:31:40 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/25 20:29:53 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int valid_letters_count(char **str)
{
	int i = 0;
	int j = 0;
	int count_p = 0;
	int count_e = 0;
	int count_c = 0;
	while (str[i])
	{
		while(str[i][j])
		{
			if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'P' && str[i][j] != 'E' && str[i][j] != 'C')
				return 0;
			if (str[i][j] == '1' && str[i][j] == '0' && str[i][j] == 'P' && str[i][j] == 'E' && str[i][j] == 'C')
				{
					if (str[i][j] == 'P')
						count_p++;
					if (str[i][j] == 'E')
						count_e++;
					if (str[i][j] == 'C')
						count_c++;
				}
				j++;
		}
		i++;
	}
		return (count_c);
}
int	is_fully_one(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] != '1'&& str[i] != '\n')
			return 0;
		i++;
	}
	return (1);
}

int is_one(char *str)
{
	int i = 0;
	
	int len = ft_strlen(str) - 1;
	while(str[i])
	{
		if (str[0] == '1' && str[len] == '1')
			return (1);
		i++;	
	}
	return (0);
}
int	t_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return (1);
		i++;
	}
	return (0);
}
char	**free_arr(char **arr)
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

char **map_parsing(int fd)
{
	char *read = get_next_line(fd);
	char *read_next = NULL;
	char **str = NULL;
	if (!is_fully_one(read))
	{
		printf("invalid entries1\n");
		free(read);
		exit(1);
	}
	while (read)
	{
		read_next = get_next_line(fd);
		if ((!t_strchr(read_next, '\n') && !is_fully_one(read_next)) || (t_strchr(read_next, '\n') && is_one(read_next)))
			{
				printf("invalid entries2\n");
				free(read);
			}
		if (read_next == NULL)
			break;
		read = ft_strjoin(read, read_next);
		free(read_next);
	}
	str = ft_split(read, '\n');
	if (valid_letters_count(str))
	{
		printf("invalid entries3\n");
		exit(1);
	}
	if (valid_letters_count(str) && free_arr(str))
	{
		printf("invalid entries3\n");
		exit(1);
	}
	free(read);
	return (str);
}

// what to do next in parsing?

// make sure there is no other entries 

// check if 'c' at least one... 
// 'e' & 'p' should be 1
 
