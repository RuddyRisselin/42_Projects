/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrisseli <rrisseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:11:28 by rrisseli          #+#    #+#             */
/*   Updated: 2024/02/08 13:32:23 by rrisseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_utils(t_data *ptr, char **map_test, int y, int i)
{
	map_test[y][i] = 'X';
	fill_arround(map_test, ptr, i, y);
}

void	open_fd(t_data *ptr, char *map_file, char *map)
{
	ptr->fd = open(map_file, O_RDONLY);
	if (ptr->fd == -1)
	{
		free(map);
		ft_error(ptr, "Error\n no fd\n");
	}
}
