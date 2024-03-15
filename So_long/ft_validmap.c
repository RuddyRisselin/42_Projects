/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:26:39 by marvin            #+#    #+#             */
/*   Updated: 2024/01/30 21:26:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_data *ptr, char **map_test)
{
	int	i;
	int	j;

	i = 0;
	while (map_test[i])
	{
		j = 0;
		while (map_test[i][j])
		{
			if (map_test[i][j] == 'E')
			{
				if (map_test[i + 1][j] == 'X' || map_test[i - 1][j] == 'X'
					|| map_test[i][j + 1] == 'X' || map_test[i][j - 1] == 'X')
						ptr->e_nb++;
			}
			j++;
		}
		i++;
	}
}

int	fill_line(char **map_test, t_data *ptr, int x, int y)
{
	int	i;

	x = 0;
	while (x < ptr->len_line - 1)
	{
		if (map_test[y][x] == 'X')
		{
			i = x;
			while (map_test[y][i] != '1' && map_test[y][i] != 'E')
			{
				check_char(map_test[y][i], ptr);
				fill_utils(ptr, map_test, y, i);
				i++;
			}
			i = x;
			while (map_test[y][i] != '1' && map_test[y][i] != 'E')
			{
				check_char(map_test[y][i], ptr);
				fill_utils(ptr, map_test, y, i);
				i--;
			}
		}
		x++;
	}
	return (0);
}

int	fill_arround(char **map_test, t_data *ptr, int x, int y)
{
	if (map_test[y + 1][x] != '1' && map_test[y + 1][x] != 'E')
	{
		check_char(map_test[y + 1][x], ptr);
		map_test[y + 1][x] = 'X';
	}
	if (map_test[y - 1][x] != '1' && map_test[y - 1][x] != 'E')
	{
		check_char(map_test[y - 1][x], ptr);
		map_test[y - 1][x] = 'X';
	}
	return (0);
}

int	find_path_c(char **map_test, t_data *ptr, int y, int x)
{
	ptr->max_line = 0;
	ptr->c_nb = 0;
	ptr->e_nb = 0;
	map_test[y][x] = 'X';
	while (ptr->c_nb != ptr->count_c || ptr->e_nb != 1)
	{
		while (y < ptr->nb_line - 1)
		{
			fill_line(map_test, ptr, x, y);
			y++;
		}
		y--;
		while (y >= 1)
		{
			fill_line(map_test, ptr, x, y);
			y--;
		}
		check_exit(ptr, map_test);
		y++;
		ptr->max_line++;
		if (ptr->max_line == (ptr->len_line * ptr->nb_line))
			return (1);
	}
	return (0);
}

int	try_find_paths(t_data *ptr)
{
	char	**map_test;
	int		i;
	int		res;

	i = 0;
	map_test = ft_split (ptr->map, '\n');
	count_collec (ptr);
	res = find_path_c(map_test, ptr, ptr->starty, ptr->startx);
	while (map_test[i])
	{
		free (map_test[i]);
		i++;
	}
	free (map_test);
	if (res == 1)
		ft_error(ptr, "Error\n No path valid");
	return (0);
}
