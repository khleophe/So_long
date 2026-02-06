/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:52:03 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/06 11:54:24 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    *read_map(char *argv)
{
    char    *line;
    char    *all_file;
    int     fd_map;

    fd_map = open(argv[1], O_RDONLY);
    if (fd == - 1)
    {
        perror("Error\nFile couldn't be openened");
        return (NULL);
    }
    line = get_next_line(fd_map);
    while (line != NULL)
    {
        
    }

}
