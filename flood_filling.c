/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_filling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:00:01 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/10 16:42:53 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **temporary_map(t_game *game)
{
    int     i;
    char    **temp_game;

    i = 0;
    while (game->map[i])
    {
        temp_game[i] = ft_strdup(game->map[i]);
        i++;
    }
    printf("%s\n", temp_game[0]);
    return (temp_game);
}

/*int flood_filling(t_game *game)
{
    int     x;
    int     y;
    int     count;

    count = 0;
    x = game->pos_x;
    y = game->pos_y;


}*/