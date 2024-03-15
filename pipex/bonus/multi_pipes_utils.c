/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipes_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrisseli <rrisseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:15:51 by rrisseli          #+#    #+#             */
/*   Updated: 2024/03/14 15:07:48 by rrisseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_in(t_data *data, char **av)
{
	if (data->nbfork == 0)
	{
		data->fd_infile = open(av[1], O_RDONLY, 0644);
		dup2(data->fd_infile, STDIN_FILENO);
		close(data->fd_infile);
	}
	else
	{
		if (data->nbfork % 2 == 0)
			dup2(data->pipe_impair[0], STDIN_FILENO);
		else
			dup2(data->pipe_pair[0], STDIN_FILENO);
	}
	close(data->pipe_pair[0]);
	close(data->pipe_impair[0]);
}

void	init_out(t_data *data, char **av, int ac)
{
	if (data->nbfork == ac - 4)
	{
		if (is_heredoc(av) == 1)
		{	
			printf("ffff");
			data->fd_outfile = open(av[ac - 1],  O_WRONLY | O_APPEND | O_CREAT, 0644);
		}
		else
			data->fd_outfile = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dup2(data->fd_outfile, STDOUT_FILENO);
		close(data->fd_outfile);
	}
	else
	{
		if (data->nbfork % 2 == 0)
			dup2(data->pipe_pair[1], STDOUT_FILENO);
		else
			dup2(data->pipe_impair[1], STDOUT_FILENO);
	}
	close(data->pipe_impair[1]);
	close(data->pipe_pair[1]);
}

void	parent(t_data *data, pid_t pid)
{
	if (data->nbfork % 2 == 0)
	{
		close(data->pipe_impair[0]);
		close(data->pipe_impair[1]);
		pipe(data->pipe_impair);
	}
	else
	{
		close(data->pipe_pair[1]);
		close(data->pipe_pair[0]);
		pipe(data->pipe_pair);
	}
	data->pid_tab[data->nbfork] = pid;
}
