/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:21:17 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/17 11:52:35 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (len != game->width)
		{
			ft_putstr("Error\nMap is not rectangular\n");
			return (1);
		}
		i++;
	}
	game->height = i;
	return (0);
}

int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width - 1)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			ft_putstr("Error\nMap must be enclosed by walls\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			ft_putstr("Error\nMap must be enclosed by walls\n");
			return (1);
		}
		i++;
	}
	return (0);
}
int	check_elements(t_game *game)
{
	int	x;
	int	y;
	int	start_position;
	int	exit;

	y = 0;
	start_position = 0;
	exit = 0;
	game->nb_collectibles = 0;
	game->count_collect = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				start_position++;
				game->pos_x = x;
				game->pos_y = y;
			}
			else if (game->map[y][x] == 'E')
				exit++;
			else if (game->map[y][x] == 'C')
				game->nb_collectibles++;
			x++;
		}
		y++;
	}
	if (start_position != 1 || exit != 1 || game->nb_collectibles < 1)
	{
		ft_putstr("Error\nNot the correct amount of elements\n");
		return (1);
	}
	return (0);
}

int	check_char(t_game *game)
{
	int	i;
	int	y;

	i = 0;
	while (game->map[i])
	{
		y = 0;
		while (game->map[i][y])
		{
			if (game->map[i][y] != 'P' && game->map[i][y] != 'E'
				&& game->map[i][y] != 'C' && game->map[i][y] != '0'
				&& game->map[i][y] != '1')
			{
				ft_putstr("Error\nThere is an unauthorized character\n");
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}
int	check_args(int argc, char *argv)
{
	int	i;
	int	len;

	len = ft_strlen(argv);
	i = 0;
	if (argc != 2)
	{
		ft_putstr("Error\nNot the right number of arguments. It should be two\n");
		return (1);
	}
	if (len <= 4 || ft_strncmp(argv + (len - 4), ".ber", 4) != 0)
	{
		ft_putstr("Error\nNot the right map format, it should be .ber\n");
		return (1);
	}
	return (0);
}
