/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:49:17 by marvin            #+#    #+#             */
/*   Updated: 2024/01/15 22:49:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*ptr;

	ptr = malloc(sizeof(t_data));
	if (!ptr)
		return (0);
	ptr->map = NULL;
	ptr->map_pars = NULL;
	ptr->fd = 0;
	ptr->mlx_ptr = mlx_init();
	if (!ptr->mlx_ptr)
		return (0);
	if (argc != 2)
		ft_error(ptr, "Error\n verify arguments");
	search_ber(argv[1], ptr);
	ft_parsing(ptr, argv[1]);
	check_error(ptr);
	ft_count_keys(ptr);
	init_img(ptr);
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ((ptr->len_line * 32) - 32), \
		(ptr->nb_line * 32), "So_long");
	mlx_key_hook(ptr->win_ptr, deal_key, ptr);
	mlx_hook(ptr->win_ptr, DestroyNotify, \
		ButtonPressMask, close_window_cross, ptr);
	mlx_loop_hook (ptr->mlx_ptr, &render_map, ptr);
	mlx_loop(ptr->mlx_ptr);
}
