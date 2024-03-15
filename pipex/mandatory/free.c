/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:44:36 by marvin            #+#    #+#             */
/*   Updated: 2024/02/26 19:44:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_data *data)
{
	free(data);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	exit_err(t_data *data, int nb, char *err_str)
{
	ft_printf("%s\n", err_str);
	if (nb > 0)
	{
		free(data);
		if (nb >= 1)
		{
			close(data->fd_infile);
			if (nb >= 2)
			{
				free(data->pid_tab);
			}
		}
	}
	free_all(data);
	exit(0);
}
