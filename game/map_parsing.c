/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:31:40 by thelmy            #+#    #+#             */
/*   Updated: 2024/06/26 13:02:13 by thelmy           ###   ########.fr       */
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
	t_node size;
	int flag = 0;
	size.height = 0;
	size.width = 0;
	
	while (str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'P' && str[i][j] != 'E' && str[i][j] != 'C')
				return 0;
			if (str[i][j] == 'P')
				count_p++;
			if (str[i][j] == 'E')
				count_e++;
			if (str[i][j] == 'C')
				count_c++;
			j++;
		}
		if (0 < j)
		{
			if (!size.width && !flag)
			{
				size.width = j;
				flag = 1;
			}
			if (size.width != j)
				return (0);
		}
		i++;
	}
	size.height = i;
	if (size.height == size.width)
		return (0);
	if (count_p != 1 || count_e != 1)
		return (0);
	return (count_c);
}
int	is_fully_one(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] != '1')
		{
			if (str[i] == '\n')
				break;
			return 0;
		}
		i++;
	} 
	return (1);
}

int is_one(char *str)
{
	
	int len = ft_strlen(str) - 1;
	if (str[0] == '1' && str[len] == '1')
		return (1);
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
		write(2, "invalid entries\n", 16);
		free(read);
		exit(1);
	}
	while (read)
	{
		read_next = get_next_line(fd);
		if (read_next == NULL)
			break;
		if ((t_strchr(read_next, '\n') == 0 && !is_fully_one(read_next)) || (t_strchr(read_next, '\n') && is_one(read_next)))
			{
				write(2, "invalid entries2\n", 17);
				free(read);
				exit(1);
			}
		read = ft_strjoin(read, read_next);
		free(read_next);
	}
	str = ft_split(read, '\n');
	if (!valid_letters_count(str))
	{
		free_arr(str);
		write(2, "invalid entries4\n", 17);
		exit(1);
	}
	free(read);
	return (str);
}

// what to do next in parsing?

// check if all line same hight 
// check if its rectangular not a square;
 
