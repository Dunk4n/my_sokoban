/*
** EPITECH PROJECT, 2018
** src/game
** File description:
** try not to segfault, good luck :)
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "menu.h"

int     game_no_map()
{
    int lv = 0;
    int win = 0;
    int sc = 0;

    while (lv < 6 && win == 0) {
        clear();
        refresh();
        win = level((char*)name_map[lv], sc);
        lv += (win == 0) ? 1 : 0;
        if (win == 0)
            sc += 100 * lv;
    }
    if (score(-1) < sc)
        score(sc);
    if (win == 0)
        return (0);
    return (1);
}
