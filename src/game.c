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

int     if_box(char **map, int i, int j)
{
    if (map[i][j] != 'X')
        return (2);
    if (((map[i - 1][j] == '#' || map[i - 1][j] == '@') ||
(map[i + 1][j] == '#' || map[i + 1][j] == '@')) && ((map[i][j - 1] == '#' ||
map[i][j - 1] == '@') || (map[i][j + 1] == '#' || map[i][j + 1] == '@')))
        return (1);
    return (0);
}

int     block(char **map)
{
    int i = 0;
    int j = 0;
    int bol = 0;

    while (map[i] != 0 && bol == 0) {
        j = 0;
        while (map[i][j] != '\0' && bol == 0) {
            bol = (if_box(map, i, j) == 0) ? 1 : 0;
            j++;
        }
        i++;
    }
    return (bol);
}

void    reset(char ***map, int **pos, int *mark, char *str)
{
    *map = get_map(str);
    *pos = player(str);
    *mark = nb_mark(str);
    (*map)[(*pos)[0]][(*pos)[1]] = ' ';
}

int     level(char *str)
{
    char **map = get_map(str);
    char dir = 0;
    int  *pos = player(str);
    int  mark = nb_mark(str);

    map[pos[0]][pos[1]] = ' ';
    while (mark > 0) {
        if (block(map) == 0)
            return (1);
        display_map(map, pos);
        dir = getch();
        if (dir == 32)
            reset(&map, &pos, &mark, str);
        else
            (dir >= 2 && dir <= 5) ? direction(map, pos, &mark, dir - 2) : 0;
        refresh();
        clear();
    }
    return (0);
}

int     game(int ac, char **av)
{
    int lv = 0;
    int win = 0;

    initscr();
    noecho();
    cbreak();
    curs_set(false);
    keypad(stdscr, true);
    win = level(av[1]);
    endwin();
    return (win);
}
