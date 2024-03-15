/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:22:42 by marvin            #+#    #+#             */
/*   Updated: 2024/01/14 13:22:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *ptr, char *close_reason)
{
	if (ptr->win_ptr != NULL)
	{
		mlx_destroy_image (ptr->mlx_ptr, ptr->img_ptr_wall);
		mlx_destroy_image (ptr->mlx_ptr, ptr->img_ptr_floor);
		mlx_destroy_image (ptr->mlx_ptr, ptr->img_ptr_door);
		mlx_destroy_image (ptr->mlx_ptr, ptr->img_ptr_collec);
		mlx_destroy_image (ptr->mlx_ptr, ptr->img_ptr_caracter);
		mlx_destroy_window (ptr->mlx_ptr, ptr->win_ptr);
		free_all(ptr);
	}
	ft_printf("%s\n", close_reason);
	exit(0);
}

int	close_window_cross(t_data *ptr)
{
	if (ptr->win_ptr != NULL)
	{
		mlx_destroy_image (ptr->mlx_ptr, ptr->img_ptr_wall);
		mlx_destroy_image (ptr->mlx_ptr, ptr->img_ptr_floor);
		mlx_destroy_image (ptr->mlx_ptr, ptr->img_ptr_door);
		mlx_destroy_image (ptr->mlx_ptr, ptr->img_ptr_collec);
		mlx_destroy_image (ptr->mlx_ptr, ptr->img_ptr_caracter);
		mlx_destroy_window (ptr->mlx_ptr, ptr->win_ptr);
		free_all(ptr);
	}
	ft_printf("Ooops You closed the window");
	exit(0);
}
