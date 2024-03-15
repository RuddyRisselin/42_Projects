/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:38:34 by marvin            #+#    #+#             */
/*   Updated: 2024/02/12 11:38:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	take_cmds(t_data *data, char **arg, int argc)
{
	int	i;
	int	j;
	int	n_cmds;

	i = 2;
	j = 0;
	n_cmds = argc - 3;
	data->cmds = malloc(sizeof(char *) * n_cmds);
	if (!data->cmds)
		exit_err(data, 2, "Erreur, mallo cmd");
	while (j < n_cmds)
	{
		data->cmds[j] = arg[i];
		i++;
		j++;
	}
	return ;
}

char	*getenv_path(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(getenv_path("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(s_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free_tab(allpath);
	ft_free_tab(s_cmd);
	return (NULL);
}

int	check_param(char *cmd, t_data *data)
{
	data->param = ft_split(cmd, ' ');
	return (0);
}

void	ft_close(t_data *data)
{
	close(data->pipefd[1]);
	close(data->pipefd[0]);
	close(data->fd_infile);
}
