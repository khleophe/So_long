/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:52:03 by sdabbas           #+#    #+#             */
/*   Updated: 2026/03/10 14:43:21 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *argv)
{
	int		count_line;
	int		fd_map;
	char	*temp;
	char	*tmp;

	count_line = 0;
	tmp = ft_calloc(1, 1);
	fd_map = open(argv, O_RDONLY);
	if (fd_map == -1)
	{
		ft_putstr("Error\nFile couldn't be opened\n");
		exit(-1);
	}
	temp = get_next_line(fd_map);
	tmp = join_tab(tmp, temp);
	while (temp != NULL)
	{
		count_line++;
		free(temp);
		temp = get_next_line(fd_map);
		tmp = join_tab(tmp, temp);
	}
	if (ft_strlen(tmp) > 0 && tmp[ft_strlen(tmp) - 1] == '\n')
		return (free(tmp), free(temp), close(fd_map), 0);
	return (free(tmp), free(temp), close(fd_map), count_line);
}

static void	removed_newline(t_game *game)
{
	int		i;
	char	len;

	len = 0;
	i = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (len > 0 && game->map[i][len - 1] == '\n')
			game->map[i][len - 1] = '\0';
		i++;
	}
}

int	read_map(char *argv, t_game *game)
{
	int	nb_line;
	int	fd_map;
	int	i;

	i = 0;
	nb_line = count_line(argv);
	if (nb_line == 0)
	{
		ft_putstr("Error\nEmpty file\n");
		exit(0);
	}
	game->map = malloc(sizeof(char *) * (nb_line + 1));
	game->height = nb_line;
	if (!game->map)
		return (1);
	fd_map = open(argv, O_RDONLY);
	while (i < nb_line)
	{
		game->map[i] = get_next_line(fd_map);
		i++;
	}
	game->map[i] = NULL;
	removed_newline(game);
	game->width = ft_strlen(game->map[0]);
	return (close(fd_map), 0);
}
