/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:43:17 by sdabbas           #+#    #+#             */
/*   Updated: 2026/03/12 15:26:08 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_screen(t_game *game)
{
	int	height;
	int	width;

	height = game->height * 60;
	width = game->width * 60;
	if (height > 1323 || width > 2560)
	{
		ft_putstr("Error\nMap too large\n");
		return (1);
	}
	return (0);
}

char	**ft_freetab(t_game *game)
{
	int	i;

	i = game->height - 1;
	while (i >= 0)
	{
		if (game->map && game->map[i])
			free(game->map[i]);
		i--;
	}
	free(game->map);
	return (NULL);
}

int	resolve_parsing(t_game *game, char *argv)
{
	if (check_args(&argv[1]) != 0)
		return (1);
	if (read_map(argv, game) != 0)
		return (ft_freetab(game), 1);
	if (game->height < 3)
		return (ft_putstr("Error\nMap is too small\n"), ft_freetab(game), 1);
	if (is_rectangular(game) != 0)
		return (ft_freetab(game), 1);
	if (check_walls(game) != 0)
		return (ft_freetab(game), 1);
	if (check_elements(game, 0, 0, 0) != 0)
		return (ft_freetab(game), 1);
	if (check_char(game) != 0)
		return (ft_freetab(game), 1);
	if (check_flood(game) != 0)
		return (ft_freetab(game), 1);
	if (check_screen(game) != 0)
		return (ft_freetab(game), 1);
	return (0);
}
