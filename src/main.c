/*
** EPITECH PROJECT, 2018
** main
** File description:
** try not to segfault, good luck :
*/

#include "my.h"
#include "menu.h"

int     main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] ==  '\0') {
        my_printf("USAGE\n\t./my_sokoban map\n");
        my_printf("DESCRIPTION\n");
        my_printf("\tmap file representing the warehouse map, containing ");
        my_printf("\'#\' for walls,\n\t\t'P' for the player, \'X\' for boxes ");
        my_printf("and 'O' for storage locations.\n");
        return (0);
    }
    return (game(ac, av));
}
