/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:53:01 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/19 13:15:14 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_data *data)
{
	data->game.steps = 0;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_putstr("Error\nNo mlx pointer\n");
		return (1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->game.width * 60,
			data->game.height * 60, "so_long");
	if (!data->win_ptr)
	{
		ft_putstr("Error\nCouldn't open the window\n");
		return (1);
	}
	return (0);
}

static void	init_image(t_data *data, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->img_w,
			&img->img_h);
	if (!img->mlx_img)
		return ;
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len,
			&img->endian);
}

void	init_asset(t_data *data)
{
	data->big.mlx_img = mlx_new_image(data->mlx_ptr, data->game.width * 60,
			data->game.height * 60);
	if (!data->big.mlx_img)
		return ;
	data->big.addr = mlx_get_data_addr(data->big.mlx_img, &data->big.bpp,
			&data->big.line_len, &data->big.endian);
	init_image(data, &data->exit, "./images/treasure.xpm");
	init_image(data, &data->floor, "./images/water.xpm");
	init_image(data, &data->player_1, "./images/first_crab.xpm");
	init_image(data, &data->player_2, "./images/second_crab.xpm");
	init_image(data, &data->star, "./images/star.xpm");
	init_image(data, &data->wall, "./images/wall.xpm");
}

static void	put_pixel(t_data *data, t_img *img, int start_y, int start_x)
{
	int		x;
	int		y;
	int		color;
	char	*dst;

	y = 0;
	while (y < img->img_h)
	{
		x = 0;
		while (x < img->img_w)
		{
			color = *(int *)(img->addr + (y * img->line_len + x * (img->bpp
							/ 8)));
			dst = data->big.addr + (y + start_y) * data->big.line_len + (x
					+ start_x) * (data->big.bpp / 8);
			*(int *)dst = color;
			x++;
		}
		y++;
	}
}

void	put_img(t_data *a, int x_big, int y_big)
{
	while (y_big < a->game.height)
	{
		x_big = 0;
		while (x_big < a->game.width)
		{
			if (a->game.map[y_big][x_big] == '1')
				put_pixel(a, &a->wall, y_big * a->wall.img_h, x_big
					* a->wall.img_w);
			if (a->game.map[y_big][x_big] == '0')
				put_pixel(a, &a->floor, y_big * a->floor.img_h, x_big
					* a->floor.img_w);
			if (a->game.map[y_big][x_big] == 'E')
				put_pixel(a, &a->exit, y_big * a->exit.img_h, x_big
					* a->exit.img_w);
			if (a->game.map[y_big][x_big] == 'P')
				put_pixel(a, &a->player_1, y_big * a->player_1.img_h, x_big
					* a->player_1.img_w);
			if (a->game.map[y_big][x_big] == 'C')
				put_pixel(a, &a->star, y_big * a->star.img_h, x_big
					* a->star.img_w);
			x_big++;
		}
		y_big++;
	}
	mlx_put_image_to_window(a->mlx_ptr, a->win_ptr, a->big.mlx_img, 0, 0);
}
