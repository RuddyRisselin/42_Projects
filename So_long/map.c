/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:57:59 by marvin            #+#    #+#             */
/*   Updated: 2024/01/17 18:57:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_entier(t_data *ptr, char *map_file)
{
	char	*map;
	char	*line;

	map = malloc(sizeof(char));
	if (!map)
		return (0);
	*map = 0;
	open_fd(ptr, map_file, map);
	line = get_next_line(ptr->fd);
	ptr->nb_line = 0;
	while (line != NULL)
	{
		if (ptr->nb_line != 0)
		{
			line = get_next_line(ptr->fd);
			if (!line)
				break ;
		}
		map = ft_strjoin_gnl(map, line);
		free(line);
		ptr->nb_line++;
	}
	close(ptr->fd);
	return (map);
}

void	ft_parsing(t_data *ptr, char *map_file)
{
	ptr->map = map_entier(ptr, map_file);
	if (!ptr->map)
		ft_error(ptr, "Error\n Empty map\n");
	ptr->map_pars = ft_split(ptr->map, '\n');
	if (!ptr->map_pars[0])
		ft_error(ptr, "Error\nmap is empty\n");
	ptr->len_line = ft_strlen(ptr->map_pars[0]);
}

int	render_map(t_data *ptr)
{
	int	x;
	int	y;

	y = 0;
	ptr->collec_total += 0;
	while (y < (ptr->nb_line))
	{
		x = 0;
		while (x < ptr->len_line)
		{
			id_sprites(ptr, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

void	id_sprites(t_data *ptr, int y, int x)
{
	char	parameter;

	parameter = ptr->map_pars[y][x];
	if (parameter == '\n' || parameter == '\0')
		return ;
	if (parameter == FLOOR)
		aff_img(ptr, ptr->img_ptr_floor, x, y);
	if (parameter == WALL)
		aff_img(ptr, ptr->img_ptr_wall, x, y);
	if (parameter == DOOR)
		aff_img(ptr, ptr->img_ptr_door, x, y);
	if (parameter == COLLEC)
		aff_img(ptr, ptr->img_ptr_collec, x, y);
	if (parameter == CHARACTER)
	{
		ptr->x_char = x;
		ptr->y_char = y;
		aff_img(ptr, ptr->img_ptr_caracter, x, y);
	}
	return ;
}

void	ft_count_keys(t_data *ptr)
{
	int	i;

	i = 0;
	while (ptr->map[i])
	{
		if (ptr->map[i] == 'C')
		{
			ptr->collec_total++;
		}
		i++;
	}
}
