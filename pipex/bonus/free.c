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

void	free_all(t_data *data, char **argv, char **av)
{
	free(data->cmds);
	if (is_heredoc(argv) == 1)
	{
		ft_free_tab(av);
		unlink("here_doc");
	}
	free(data->pid_tab);
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
		if (nb >= 1)
		{
			free(data->pid_tab);
			free(data->cmds);
			if (nb >= 2)
			{
				close(data->fd_infile);
			}
		}
	free(data);
	exit(0);
}
