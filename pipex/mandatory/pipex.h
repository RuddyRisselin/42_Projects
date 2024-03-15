/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:34:45 by marvin            #+#    #+#             */
/*   Updated: 2024/02/12 11:34:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		fd_outfile;
	int		fd_infile;
	int		nbfork;
	char	**cmds;
	char	**param;
	int		pipefd[2];
	int		*pid_tab;
	pid_t	pid;
}	t_data;

int		main(int argc, char **argv, char **envp);
void	free_all(t_data *data);
void	exit_err(t_data *data, int nb, char *err_str);
void	take_cmds(t_data *data, char **arg, int argc);
void	ft_free_tab(char **tab);
char	*get_path(char *cmd, char **env);
char	*getenv_path(char *name, char **env);
int		check_param(char *cmd, t_data *data);
void	process1(t_data *data, char **env, int ac, char **av);
void	ft_close(t_data *data);
void	pipex_init(int argc, char **argv, t_data *data);
void	init_in_out(t_data *data, char **av, int ac);

#endif