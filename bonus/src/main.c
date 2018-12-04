/*
** EPITECH PROJECT, 2018
** main
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include "my.h"
#include "menu.h"

const char *name_map[5] = {"map/map1", "map/map2", "map/map3", "map/map4",
"map/map5"};

int     main(int ac, char **av)
{
    if (ac > 2)
        return (84);
    if (ac == 2)
        menu(av[1]);
    if (ac == 1)
        menu(NULL);
    return (0);
}
