/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:48:59 by marvin            #+#    #+#             */
/*   Updated: 2024/01/15 22:48:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define FLOOR_XPM		"Game_assets/Floor.xpm"
# define WALL_XPM		"Game_assets/Wall.xpm"
# define DOOR_XPM		"Game_assets/Door_close.xpm"
# define CHARACTER_XPM	"Game_assets/Character.xpm"
# define COLLEC_XPM		"Game_assets/Collec.xpm"

# define FLOOR			'0'
# define WALL			'1'
# define DOOR			'E'
# define CHARACTER		'P'
# define COLLEC			'C'

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr_floor;
	void		*img_ptr_wall;
	void		*img_ptr_door;
	void		*img_ptr_collec;
	void		*img_ptr_caracter;
	void		*xpm_ptr;	
	char		**map_pars;
	char		*map;
	int			fd;
	int			nb_line;
	int			len_line;
	int			collec;
	int			collec_total;
	int			nb_move;
	int			x_char;
	int			y_char;
	int			count_e;
	int			count_c;
	int			e_nb;
	int			c_nb;
	int			startx;
	int			starty;
	char		**map_test;
	int			max_line;
}	t_data;

int		main(int argc, char **argv);

int		close_window(t_data *ptr, char *close_reason);
int		close_window_cross(t_data *ptr);
int		deal_key(int key, t_data *ptr);
void	free_all(t_data *ptr);

int		render_map(t_data *ptr);
void	id_sprites(t_data *ptr, int x, int y);
void	init_img(t_data *ptr);
void	aff_img(t_data *ptr, void *img_ptr, int x, int y);

void	ft_parsing(t_data *ptr, char *map_file);
char	*map_entier(t_data *ptr, char *map_file);
void	ft_count_keys(t_data *ptr);

void	ft_move_forward(t_data *ptr);
void	ft_move_back(t_data *ptr);
void	ft_move_right(t_data *ptr);
void	ft_move_left(t_data *ptr);

int		ft_error(t_data *ptr, char *str_error);
int		check_format(t_data *ptr);
int		search_ber(char *arg, t_data *ptr);
void	check_error(t_data *ptr);
int		check_col(t_data *ptr);
int		check_line(t_data *ptr);
int		check_content(t_data *ptr);
int		check_unknown(t_data *ptr);

int		try_find_paths(t_data *ptr);
void	count_collec(t_data *ptr);
int		find_path_c(char **map_test, t_data *ptr, int y, int x);
int		fill_arround(char **map_test, t_data *ptr, int x, int y);
int		fill_line(char **map_test, t_data *ptr, int x, int y);
void	check_char(char char_map, t_data *ptr);
void	check_exit(t_data *ptr, char **map_test);
void	fill_utils(t_data *ptr, char **map_test, int y, int i);
void	open_fd(t_data *ptr, char *map_file, char *map);

#endif