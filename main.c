/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:22:48 by sdabbas           #+#    #+#             */
/*   Updated: 2026/02/10 22:37:01 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//main de test
int main(int argc, char **argv)
{
    t_game  game;
    int     i;

    check_args(argc, argv[1]);
    read_map(argv[1], &game);
    if (game.map)
    {
        printf("Succès ! Voici le contenu de game.map :\n");
        i = 0;
        while (game.map[i])
        {
            printf("Ligne [%d] : %s\n", i, game.map[i]);
            i++;
        }
    }
    else
        printf("Échec : game.map est NULL\n");
        is_rectangular(&game);
        check_walls(&game);
        check_elements(&game);
        check_char(&game);
        check_flood(&game);
    return (0);
}