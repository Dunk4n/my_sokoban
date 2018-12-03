/*
** EPITECH PROJECT, 2018
** size_map
** File description:
** try not to segfault, good luck :)
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "menu.h"

int     size_map(char **map)
{
    char    str[] = "Do you want to enlarge your terminal?";
    int     col = 0;
    int     i = 0;
    int     j = 0;

    while (map[i] != 0) {
        j = 0;
        while (map[i][j] != '\0')
            j++;
        col = (j > col) ? j : col;
        i++;
    }
    if (LINES < i || COLS < col) {
        mvprintw(LINES / 2,  COLS / 2 - my_strlen(str) / 2, str);
        return (1);
    }
    return (0);
}

int     nblig(char **map)
{
    int i = 0;

    while (map[i] != 0)
        i++;
    return (i);
}
