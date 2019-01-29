/*
** EPITECH PROJECT, 2018
** src/game_add
** File description:
** try not to segfault, good luck :)
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "menu.h"

int     game_add(char ***map, int **pos, char *str, int *mark)
{
    int dir = 0;

    (size_map(*map) == 0) ? display_map(*map, *pos) : 0;
    refresh();
    clear();
    dir = input();
    if (dir == 6)
        return (1);
    if (dir == 5)
        reset(map, pos, mark, str);
    else
        (dir >= 1 && dir <= 4) ? direction(*map, *pos, mark, dir - 1) : 0;
    return (0);
}
