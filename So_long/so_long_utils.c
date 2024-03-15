/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:49:05 by marvin            #+#    #+#             */
/*   Updated: 2024/01/15 22:49:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(t_data *ptr, char *str_error)
{
	free_all(ptr);
	ft_printf("%s", str_error);
	exit (0);
}

void	check_error(t_data *ptr)
{
	ptr->nb_move = 0;
	ptr->collec = 0;
	ptr->collec_total = 0;
	check_unknown(ptr);
	check_content(ptr);
	check_col(ptr);
	check_line(ptr);
	check_format(ptr);
	try_find_paths(ptr);
}

void	count_collec(t_data *ptr)
{
	int	i;
	int	j;

	i = 0;
	ptr->count_c = 0;
	while (i < ptr->nb_line)
	{
		j = 0;
		while (j < ptr->len_line)
		{
			if (ptr->map_pars[i][j] == 'C')
				ptr->count_c++;
			if (ptr->map_pars[i][j] == 'P')
			{
				ptr->starty = i;
				ptr->startx = j;
			}
			j++;
		}
		i++;
	}
}

void	check_char(char char_map, t_data *ptr)
{
	if (char_map == 'E')
		ptr->e_nb++;
	if (char_map == 'C')
		ptr->c_nb++;
}

int	search_ber(char *arg, t_data *ptr)
{
	int	i;

	i = ft_strlen(arg);
	if (arg[i - 1] != 'r')
		ft_error(ptr, "Error\n verify arguments extention");
	if (arg[i - 2] != 'e')
		ft_error(ptr, "Error\n verify arguments extention");
	if (arg[i - 3] != 'b')
		ft_error(ptr, "Error\n verify arguments extention");
	if (arg[i - 4] != '.')
		ft_error(ptr, "Error\n verify arguments extention");
	return (1);
}
