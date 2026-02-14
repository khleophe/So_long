/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:22:48 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/14 16:13:02 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	main(int argc, char **argv)
{
	t_data	data;
	ft_memset(&data, 0, sizeof(t_data));
	resolve_parsing(&data.game, argc, argv[1]);
	init_game(&data);
	init_asset(&data);
	// free tt si fct renvoie 1;
	mlx_loop(data.mlx_ptr);
	
	return (0);
}*/

int main(int argc, char **argv)
{
    t_data  data;

    // On écrit directement sur la sortie d'erreur (fd 2)
    write(2, "--- LANCEMENT DU PROGRAMME ---\n", 31);
    
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
	write(2, "img\n", 4);
	
    mlx_loop(data.mlx_ptr);
    return (0);
}