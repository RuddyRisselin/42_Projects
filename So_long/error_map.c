/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:12:55 by marvin            #+#    #+#             */
/*   Updated: 2024/01/24 12:12:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_col(t_data *ptr)
{
	int	i;

	i = 0;
	while (ptr->map_pars[i])
	{
		if (ptr->map_pars[i][0] != WALL
			|| ptr->map_pars[i][ptr->len_line - 2] != WALL)
		{
			ft_error(ptr, "Error\nMap column not close\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_line(t_data *ptr)
{
	int		i;

	i = 0;
	while (i < ptr->len_line - 1)
	{
		if (ptr->map_pars[0][i] != '1')
		{
			ft_error(ptr, "Error\nMap first line not close\n");
			return (0);
		}
		if (ptr->map_pars[ptr->nb_line - 1][i] != '1')
		{
			ft_error(ptr, "Error\nMap last line not close\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_content(t_data *ptr)
{
	int	i;
	int	count_c;
	int	count_col;

	i = 0;
	count_c = 0;
	count_col = 0;
	ptr->count_e = 0;
	while (ptr->map[i])
	{
		if (ptr->map[i] == CHARACTER)
			count_c++;
		if (ptr->map[i] == DOOR)
			ptr->count_e++;
		if (ptr->map[i] == COLLEC)
			count_col++;
		i++;
	}
	if (count_c != 1 || ptr->count_e != 1 || count_col < 1)
	{	
		ft_error(ptr, "Error\n Check your map content\n");
		return (0);
	}
	return (1);
}

int	check_unknown(t_data *ptr)
{
	int	i;
	int	j;

	j = 0;
	while (j < ptr->nb_line)
	{
		i = 0;
		while (i < ptr->len_line - 1)
		{
			if (ptr->map_pars[j][i] != '1' && ptr->map_pars[j][i] != 'E'
					&& ptr->map_pars[j][i] != '0' && ptr->map_pars[j][i] != 'P'
					&& ptr->map_pars[j][i] != 'C')
			{
				ft_error(ptr, "Error\ninvalid content\n");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	check_format(t_data *ptr)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	size = ptr->len_line;
	while (j < ptr->nb_line)
	{
		i = 0;
		if (j == ptr->nb_line - 1)
			size = size - 1;
		while (i < size)
		{
			if (ft_strlen(ptr->map_pars[j]) != size)
				ft_error(ptr, "Error\ninvalid format\n");
			i++;
		}
		j++;
	}
	return (1);
}
