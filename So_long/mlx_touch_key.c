/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_touch_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:11:43 by marvin            #+#    #+#             */
/*   Updated: 2024/01/16 14:11:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_key(int key, t_data *ptr)
{
	if (key == 119 || key == 122)
		ft_move_forward(ptr);
	if (key == 115)
		ft_move_back(ptr);
	if (key == 97 || key == 113)
		ft_move_left(ptr);
	if (key == 100)
		ft_move_right(ptr);
	if (key == 65307)
		close_window(ptr, "Oops you closed the window");
	return (0);
}

void	ft_move_forward(t_data *ptr)
{
	if ((ptr->map_pars[(ptr->y_char) - 1][ptr->x_char] == '0')
		|| (ptr->map_pars[(ptr->y_char) - 1][ptr->x_char] == 'C')
		|| (ptr->map_pars[(ptr->y_char) - 1][ptr->x_char] == 'E'))
	{
		if (ptr->map_pars[(ptr->y_char) - 1][ptr->x_char] == 'C')
		{
			ptr->collec++;
			ft_printf("Key : %d/%d\n", ptr->collec, ptr->collec_total);
		}
		if (ptr->map_pars[(ptr->y_char) - 1][ptr->x_char] == 'E')
		{
			if (ptr->collec == ptr->collec_total)
				close_window(ptr, "You Win");
			if (ptr->collec != ptr->collec_total)
				return ;
		}
		ptr->map_pars[(ptr->y_char) - 1][ptr->x_char] = 'P';
		ptr->map_pars[(ptr->y_char)][ptr->x_char] = '0';
		ptr->nb_move++;
		ft_printf("%d\n", ptr->nb_move);
		ptr->y_char = ptr->y_char - 1;
	}
}

void	ft_move_back(t_data *ptr)
{
	if ((ptr->map_pars[(ptr->y_char) + 1][ptr->x_char] == '0')
		|| (ptr->map_pars[(ptr->y_char) + 1][ptr->x_char] == 'C')
		|| (ptr->map_pars[(ptr->y_char) + 1][ptr->x_char] == 'E'))
	{
		if (ptr->map_pars[(ptr->y_char) + 1][ptr->x_char] == 'C')
		{
			ptr->collec++;
			ft_printf("Key : %d/%d\n", ptr->collec, ptr->collec_total);
		}
		if (ptr->map_pars[(ptr->y_char) + 1][ptr->x_char] == 'E')
		{
			if (ptr->collec == ptr->collec_total)
				close_window(ptr, "You Win");
			if (ptr->collec != ptr->collec_total)
				return ;
		}
		ptr->map_pars[(ptr->y_char) + 1][ptr->x_char] = 'P';
		ptr->map_pars[ptr->y_char][ptr->x_char] = '0';
		ptr->nb_move++;
		ft_printf("%d\n", ptr->nb_move);
		ptr->y_char = ptr->y_char + 1;
	}
}

void	ft_move_right(t_data *ptr)
{
	if ((ptr->map_pars[ptr->y_char][(ptr->x_char + 1)] == '0')
		|| (ptr->map_pars[ptr->y_char][(ptr->x_char + 1)] == 'C')
		|| (ptr->map_pars[ptr->y_char][(ptr->x_char + 1)] == 'E'))
	{
		if (ptr->map_pars[ptr->y_char][(ptr->x_char + 1)] == 'C')
		{
			ptr->collec++;
			ft_printf("Key : %d/%d\n", ptr->collec, ptr->collec_total);
		}
		if (ptr->map_pars[ptr->y_char][(ptr->x_char + 1)] == 'E')
		{
			if (ptr->collec == ptr->collec_total)
				close_window(ptr, "You Win");
			if (ptr->collec != ptr->collec_total)
				return ;
		}
		ptr->map_pars[ptr->y_char][(ptr->x_char + 1)] = 'P';
		ptr->map_pars[ptr->y_char][ptr->x_char] = '0';
		ptr->nb_move++;
		ft_printf("%d\n", ptr->nb_move);
		ptr->y_char = ptr->y_char + 1;
	}
}

void	ft_move_left(t_data *ptr)
{
	if ((ptr->map_pars[ptr->y_char][(ptr->x_char - 1)] == '0')
		|| (ptr->map_pars[ptr->y_char][(ptr->x_char - 1)] == 'C')
		|| (ptr->map_pars[ptr->y_char][(ptr->x_char - 1)] == 'E'))
	{
		if (ptr->map_pars[ptr->y_char][(ptr->x_char - 1)] == 'C')
		{
			ptr->collec++;
			ft_printf("Key : %d/%d\n", ptr->collec, ptr->collec_total);
		}
		if (ptr->map_pars[ptr->y_char][(ptr->x_char - 1)] == 'E')
		{
			if (ptr->collec == ptr->collec_total)
				close_window(ptr, "You Win");
			if (ptr->collec != ptr->collec_total)
				return ;
		}
		ptr->map_pars[ptr->y_char][(ptr->x_char - 1)] = 'P';
		ptr->map_pars[ptr->y_char][ptr->x_char] = '0';
		ptr->nb_move++;
		ft_printf("%d\n", ptr->nb_move);
		ptr->y_char = ptr->y_char - 1;
	}
}
