/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:22:48 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/16 18:20:19 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_data  data;

    ft_memset(&data, 0, sizeof(t_data));
    if (argc != 2)
        return (write(2, "Erreur Argc\n", 12), 1);

    resolve_parsing(&data.game, argc, argv[1]);
    write(2, "Parsing OK\n", 11);

    init_game(&data);
    write(2, "MLX Init OK\n", 12);

    init_asset(&data);
    write(2, "Assets OK\n", 10);

	put_img(&data);
	write(2, "img OK\n", 7);

    mlx_hook(data.win_ptr, 2, 1L<<0, key_hook, &data);
    mlx_hook(data.win_ptr, 17, 0, close_map, &data);
	
    mlx_loop(data.mlx_ptr);
    close_map(&data);
    return (0);
}