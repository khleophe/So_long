/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:21:17 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/09 17:58:02 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	/*if (!game->map || !game->map[i])
	{
		write(1, "Error, map is empty\n", 19);
		return (1);
	}*/
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (len != game->width)
		{
			write(1, "Error, map is not rectangular\n", 29);
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
	int	i;
	int	start_position;
	int	exit;

	i = 0;
	start_position = 0;
	exit = 0;
	game->nb_collectibles = 0;
	while (game->map[i])
	{
		if (ft_strchr(game->map[i], 'P'))
			start_position++;
		if (ft_strchr(game->map[i], 'E'))
			exit++;
		if (ft_strchr(game->map[i], 'C'))
			game->nb_collectibles++;
		i++;
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
    int y;

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
