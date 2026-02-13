/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:53:01 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/13 20:04:25 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_game(t_data *data)
{
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
    {
        ft_putstr("Error\nNo mlx pointer\n");
        return (0); 
    }  // msg d'erreur peut etre
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
    if (!data->win_ptr)
    {  
        ft_putstr("Error\nCouldn't open the window\n");
        return (0);
    }
    while (1) // remplacer par mlx_loop + mlx_*hook;
        ; //ici pt s'arreter la fct init
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    return (1);
}
static void init_image(t_data *data, t_img *img, char *path)
{ 
    img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->img_w, &img->img_h);
    if (!img->mlx_img)
    {
        //ftc free ?
        return ;
    }
    img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
}
void init_asset(t_data *data)
{
    
    data->big.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!data->big.mlx_img)
        return ;
    data->big.addr = mlx_get_data_addr(data->big.mlx_img, &data->big.bpp, &data->big.line_len, &data->big.endian);
    init_image(data, &data->exit, "./images/treasure.xpm");
    init_image(data,&data->floor, "./images/water.xpm");
    init_image(data, &data->player_1, "./images/first_crab.xpm");
    init_image(data, &data->player_2, "./images/second_crab.xpm");
    init_image(data, &data->star, "./images/star.xpm");
    init_image(data, &data->wall, "./images/wall.xpm");    
}

