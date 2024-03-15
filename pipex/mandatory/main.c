/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:30:57 by marvin            #+#    #+#             */
/*   Updated: 2024/02/12 11:30:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_child(t_data *data, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 3)
	{
		waitpid(data->pid_tab[i], NULL, 0);
		i++;
	}
}

void	process1(t_data *data, char **env, int ac, char **av)
{
	char	*cmd;

	init_in_out(data, av, ac);
	cmd = get_path(data->cmds[data->nbfork], env);
	if (!cmd)
	{
		free(data->cmds);
		free(data->pid_tab);
		free(data);
		exit(0);
	}
	check_param(data->cmds[data->nbfork], data);
	execve(cmd, data->param, env);
}

void	init_in_out(t_data *data, char **av, int ac)
{
	if (data->nbfork == 0)
	{
		dup2(data->fd_infile, STDIN_FILENO);
		close(data->fd_infile);
	}
	else
		dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[0]);
	if (data->nbfork == 0)
		dup2(data->pipefd[1], STDOUT_FILENO);
	else
	{
		data->fd_outfile = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (data->fd_outfile == -1)
			exit_err(data, 3, "Erreur, verifier l'outfile");
		dup2(data->fd_outfile, STDOUT_FILENO);
		close(data->fd_outfile);
	}
	close(data->pipefd[1]);
}

void	pipex_init(int argc, char **argv, t_data *data)
{
	data->nbfork = 0;
	data->fd_infile = open(argv[1], O_RDONLY);
	if (data->fd_infile == -1)
		exit_err(data, 0, "Erreur, vérifier l'infile");
	take_cmds(data, argv, argc);
	data->pid_tab = malloc(sizeof(pid_t) * (argc - 3));
	if (!data->pid_tab)
		exit_err(data, 1, "Erreur, Malloc Pid");
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (!envp || argc != 5)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	pipex_init(argc, argv, data);
	pipe(data->pipefd);
	while ((data->nbfork) < (argc - 3))
	{
		data->pid = fork();
		if (data->pid == -1)
			exit_err(data, 2, "Erreur, fork");
		else if (data->pid == 0)
			process1(data, envp, argc, argv);
		else
			data->pid_tab[data->nbfork] = data->pid;
		data->nbfork++;
	}
	ft_close(data);
	wait_child(data, argc);
	free(data->cmds);
	free(data->pid_tab);
	free(data);
}
