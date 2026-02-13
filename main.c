/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:22:48 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/13 20:02:07 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_data	data;

	data.mlx_ptr = NULL;
	data.mlx_ptr = NULL;
	game.map = NULL;
	resolve_parsing(&game, argc, argv[1]);
	init_game(&data);
	// free tt si fct renvoie 1;
	init_asset(&data);
	return (0);
}