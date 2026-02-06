/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:52:03 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/06 17:15:12 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int  count_line(char *argv)
{
    int     count_line;
    int     fd_map;
    char    *temp;

    count_line = 0;
    fd_map = open(argv, O_RDONLY);
    if (fd_map == -1)
    {
        perror("Error\nFile couldn't be opened");
        return (-1);
    }
    while ((temp = get_next_line(fd_map))!= NULL)
    {
        count_line++;
        free(temp);
    }
    close(fd_map);
    return (count_line);
}

void    read_map(char *argv, t_game *game)
{
    int     nb_line;
    int     fd_map;
    int     i;

    i = 0;
    nb_line = count_line(argv);
    game->map = malloc(sizeof (char*) * (nb_line + 1));
    if (!game->map)
        return ;
    fd_map = open(argv, O_RDONLY);
    while (i < nb_line)
    {
       game->map[i] = get_next_line(fd_map);
       i++;
    }
    game->map[i] = NULL;
    close(fd_map);
}    
