/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:22:48 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/17 11:52:48 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (resolve_parsing(&data.game, argc, argv[1]) != 0)
		return (1);
	init_game(&data);
	init_asset(&data);
	put_img(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, close_map, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}