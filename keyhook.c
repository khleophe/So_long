/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:01:54 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/16 17:26:26 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_move(t_data *data, int x, int y)
{
	int	new_position_x;
	int	new_position_y;

	new_position_x = data->game.pos_x + x;
	new_position_y = data->game.pos_y + y;
	if (data->game.map[new_position_y][new_position_x] == '1')
		return ;
	if (data->game.map[new_position_y][new_position_x] == 'E')
	{
		if (data->game.count_collect == data->game.nb_collectibles)
			close_map(data);
		return ;
	}
	if (data->game.map[new_position_y][new_position_x] == '0'
		|| data->game.map[new_position_y][new_position_x] == 'C')
	{
		if (data->game.map[new_position_y][new_position_x] == 'C')
			data->game.count_collect++;
		data->game.map[data->game.pos_y][data->game.pos_x] = '0';
		data->game.pos_y = new_position_y;
		data->game.pos_x = new_position_x;
		data->game.map[data->game.pos_y][data->game.pos_x] = 'P';
		put_img(data);
	}
}

int	key_hook(int key, t_data *data)
{
    if (key == ESC)
        close_map(data);
    if (key == KEY_W || key == UP)
        player_move(data, 0, -1);
    if (key == KEY_S || key == DOWN)
        player_move(data, 0, 1);
    if (key == KEY_A || key == LEFT)
        player_move(data, -1, 0);
    if (key == KEY_D || key == RIGHT)
        player_move(data, 1, 0);
    return (0);
}
