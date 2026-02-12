/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:53:01 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/12 18:43:31 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_game(t_data *data)
{
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
        return (0); // msg d'erreur peut etre
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
    if (!data->win_ptr)
        return (0);
    while (1) // remplacer par mlx_loop + mlx_*hook;
        ; //ici pt s'arreter la fct init
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
}
