/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:18:06 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/10 21:29:08 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define STARTING_POS 'P'

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		nb_collectibles;
	int		pos_x;
	int		pos_y;
}			t_game;

// map

int			count_line(char *argv);
void		read_map(char *argv, t_game *game);
int			is_rectangular(t_game *game);
int			check_walls(t_game *game);
int			check_elements(t_game *game);
int			check_char(t_game *game);
int			check_args(int argc, char *argv);
int 		check_flood(t_game *game);


void	ft_putstr(char *str);

#endif