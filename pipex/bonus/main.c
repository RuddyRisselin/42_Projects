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
	while (i < ac - 4)
	{
		waitpid(data->pid_tab[i], NULL, 0);
		i++;
	}
}

void	process1(t_data *data, char **env, int ac, char **av)
{
	char	*cmd;

	init_in(data, av);
	init_out(data, av, ac);
	cmd = get_path(data->cmds[data->nbfork], env);
	if (!cmd)
	{
		free(data->cmds);
		free(cmd);
		free(data->pid_tab);
		free(data);
		exit(0);
	}
	check_param(data->cmds[data->nbfork], data);
	execve(cmd, data->param, env);
}

void	pipex_init(int argc, char **av, t_data *data)
{
	int	i;

	i = 0;
	data->nbfork = 0;
	take_cmds(data, av, argc);
	data->pid_tab = malloc(sizeof(pid_t) * (argc - 3));
	if (!data->pid_tab)
		exit_err(data, 0, "Erreur, Malloc Pid tab");
	while (i < argc - 3)
		data->pid_tab[i++] = 0;
	data->fd_infile = open(av[1], O_RDONLY);
	if (data->fd_infile == -1)
		exit_err(data, 1, "Erreur, vérifier l'infile");
	data->fd_outfile = open(av[argc - 1], O_WRONLY);
	if (data->fd_outfile == -1)
		return ;
	close(data->fd_infile);
	close(data->fd_outfile);
	pipe(data->pipe_impair);
	pipe(data->pipe_pair);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	pid_t	pid;
	char	**av;
	int		ac;

	if (!envp || argc < 5)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	av = check_av(argv, argc);
	if (is_heredoc(argv) == 1)
		ac = pipex_heredoc(argv, argc);
	else
		ac = argc;
	pipex_init(ac, av, data);
	while ((data->nbfork) < (ac - 3))
	{
		pid = fork();
		if (pid == -1)
			exit_err(data, 2, "Erreur, fork");
		else if (pid == 0)
			process1(data, envp, ac, av);
		else
			parent(data, pid);
		data->nbfork++;
	}
	ft_close(data);
	wait_child(data, ac);
	free_all(data, argv, av);
}
