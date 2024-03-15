/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:20:11 by marvin            #+#    #+#             */
/*   Updated: 2024/01/17 17:20:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_data *ptr)
{
	int	i;

	i = 0;
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->mlx_ptr);
	if (ptr->map != NULL)
		free(ptr->map);
	if (ptr->map_pars != NULL)
	{
		while (ptr->map_pars[i])
		{
			free(ptr->map_pars[i]);
			i++;
		}
		free(ptr->map_pars);
	}
	free(ptr);
}
