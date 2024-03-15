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

# define FREE_BUFFER 1

typedef struct s_data
{
	int		fd_outfile;
	int		fd_infile;
	int		nbfork;
	int		pipe_impair[2];
	int		pipe_pair[2];
	int		*pid_tab;
	char	**cmds;
	char	**param;
}	t_data;

int		main(int argc, char **argv, char **envp);
int		is_heredoc(char **av);
int		check_param(char *cmd, t_data *data);
char	*getenv_path(char *name, char **env);
char	*get_path(char *cmd, char **env);
char	**check_av(char **argv, int argc);
void	exit_err(t_data *data, int nb, char *err_str);
void	take_cmds(t_data *data, char **av, int argc);
void	ft_free_tab(char **tab);
void	process1(t_data *data, char **env, int ac, char **av);
void	ft_close(t_data *data);
void	pipex_init(int argc, char **av, t_data *data);
void	init_in(t_data *data, char **av);
void	init_out(t_data *data, char **av, int ac);
void	parent(t_data *data, pid_t pid);
void	free_all(t_data *data, char **argv, char **av);
int		pipex_heredoc(char **av, int argc);

#endif