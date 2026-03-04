/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:01:54 by sdabbas           #+#    #+#             */
/*   Updated: 2026/03/04 14:05:05 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	player_move(t_data *data, int x, int y)
{
	int	new_position_x;
	int	new_position_y;

	new_position_x = data->game.pos_x + x;
	new_position_y = data->game.pos_y + y;
	if (data->game.map[new_position_y][new_position_x] == '1')
		return (1);
	if (data->game.map[new_position_y][new_position_x] == 'E')
	{
		if (data->game.count_collect == data->game.nb_collectibles)
			close_map(data);
		return (1);
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
		put_img(data, 0, 0);
	}
	return (0);
}

int	key_hook(int key, t_data *data)
{
	if (key == ESC)
		close_map(data);
	if (key == KEY_W || key == UP)
		if (player_move(data, 0, -1) == 0)
			printf("%i\n", ++data->game.steps);
	if (key == KEY_S || key == DOWN)
		if (player_move(data, 0, 1) == 0)
			printf("%i\n", ++data->game.steps);
	if (key == KEY_A || key == LEFT)
		if (player_move(data, -1, 0) == 0)
			printf("%i\n", ++data->game.steps);
	if (key == KEY_D || key == RIGHT)
		if (player_move(data, 1, 0) == 0)
			printf("%i\n", ++data->game.steps);
	return (0);
}
