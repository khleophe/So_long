/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:43:17 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/19 13:08:17 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_freetab(t_game *game)
{
	int	i;

	i = game->height - 1;
	while (i >= 0)
	{
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
	read_map(argv, game);
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
	return (0);
}
