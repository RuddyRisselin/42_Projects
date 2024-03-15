/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:21:41 by marvin            #+#    #+#             */
/*   Updated: 2024/01/17 21:21:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_data *ptr)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	ptr->img_ptr_floor = mlx_xpm_file_to_image(ptr->mlx_ptr, FLOOR_XPM, &width,
			&height);
	ptr->img_ptr_wall = mlx_xpm_file_to_image(ptr->mlx_ptr, WALL_XPM, &width,
			&height);
	ptr->img_ptr_door = mlx_xpm_file_to_image(ptr->mlx_ptr, DOOR_XPM, &width,
			&height);
	ptr->img_ptr_caracter = mlx_xpm_file_to_image(ptr->mlx_ptr, CHARACTER_XPM,
			&width, &height);
	ptr->img_ptr_collec = mlx_xpm_file_to_image(ptr->mlx_ptr, COLLEC_XPM,
			&width, &height);
	if (!ptr->img_ptr_floor || !ptr->img_ptr_wall || !ptr->img_ptr_door
		|| !ptr->img_ptr_caracter || !ptr->img_ptr_collec)
		ft_error(ptr, "Error\n no xpm file found\n");
}

void	aff_img(t_data *ptr, void *img_ptr, int x, int y)
{
	int	x_px;
	int	y_px;

	x_px = x * 32;
	y_px = y * 32;
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, img_ptr, x_px, y_px);
}
