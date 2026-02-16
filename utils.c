/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:13:45 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/16 16:45:29 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**freetab(char **dest, int i)
{
    if (!dest)
        return (NULL);
	while (i >= 0)
	{
        if (dest[i])
		    free(dest[i]);
		i--;
	}
	free(dest);
	return (NULL);
}

int close_map(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->wall.mlx_img);
    mlx_destroy_image(data->mlx_ptr, data->floor.mlx_img);
    mlx_destroy_image(data->mlx_ptr, data->star.mlx_img);
    mlx_destroy_image(data->mlx_ptr, data->player_1.mlx_img);
    mlx_destroy_image(data->mlx_ptr, data->player_2.mlx_img);
    mlx_destroy_image(data->mlx_ptr, data->exit.mlx_img);
    mlx_destroy_image(data->mlx_ptr, data->big.mlx_img);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    freetab(data->game.map, data->game.height);
    return (0);
}