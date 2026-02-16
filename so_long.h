/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:18:06 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/16 17:35:55 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>


# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define STARTING_POS 'P'
# define ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		nb_collectibles;
	int		count_collect;
	int		pos_x;
	int		pos_y;
}			t_game;

typedef	struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		img_h;
	int		img_w;	
}		t_img;

typedef	struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_game	game;
	t_img	wall;
	t_img	floor;
	t_img	star;
	t_img	player_1;
	t_img	player_2;
	t_img	exit;
	t_img	big;
}		t_data;

// map

int			count_line(char *argv);
void		read_map(char *argv, t_game *game);
int			is_rectangular(t_game *game);
int			check_walls(t_game *game);
int			check_elements(t_game *game);
int			check_char(t_game *game);
int			check_args(int argc);
int			check_flood(t_game *game);
int			resolve_parsing(t_game *game, int argc, char *argv);

// game

int			init_game(t_data *data);
void		init_asset(t_data *data);
void    	put_img(t_data *data);
int			key_hook(int key, t_data *data);

// tools

char	**freetab(char **dest, int i);
int		close_map(t_data *data);

#endif