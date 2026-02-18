/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_filling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:00:01 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/18 13:44:25 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**temporary_map(t_game *game)
{
	int		i;
	char	**temp_game;

	temp_game = malloc(sizeof(char *) * (game->height + 1));
	if (!temp_game)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		temp_game[i] = ft_strdup(game->map[i]);
		i++;
	}
	temp_game[i] = NULL;
	return (temp_game);
}

static void	flood_filling(t_game *game, char **temp_map, int y, int x)
{
	if (temp_map[y][x] == '1' || temp_map[y][x] == 'A')
		return ;
	temp_map[y][x] = 'A';
	flood_filling(game, temp_map, y + 1, x);
	flood_filling(game, temp_map, y - 1, x);
	flood_filling(game, temp_map, y, x + 1);
	flood_filling(game, temp_map, y, x - 1);
}

int	check_flood(t_game *game)
{
	int		i;
	int		j;
	char	**temp_map;

	temp_map = temporary_map(game);
	flood_filling(game, temp_map, game->pos_y, game->pos_x);
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (temp_map[i][j] == 'C' || temp_map[i][j] == 'E')
			{
				ft_putstr("Error\n: inaccessible collectible or exit\n");
				freetab(temp_map, game->height);
				return (1);
			}
			j++;
		}
		i++;
	}
	freetab(temp_map, game->height);
	return (0);
}
