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
    if (((i - 1 < 0 || map[i - 1][j] == '#' || map[i - 1][j] == '@' ||
map[i - 1][j] == 'X') || (i + 1 > nblig(map) || map[i + 1][j] == '#' ||
map[i + 1][j] == '@' || map[i + 1][j] == 'X')) && ((j - 1 < 0 ||
map[i][j - 1] == '#' || map[i][j - 1] == '@' || map[i][j - 1] == 'X') ||
(j + 1 >= my_strlen(map[i]) || map[i][j + 1] == '#' || map[i][j + 1] == '@' ||
map[i][j + 1] == 'X')))
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

int     level(char *str, int sc)
{
    char **map = get_map(str);
    int  *pos = player(str);
    int  mark = nb_mark(str);

    map[pos[0]][pos[1]] = ' ';
    while (mark > 0) {
        if (block(map) == 0)
            return (1);
        printw("name: %s    score: %d\n\n", str, sc);
        if (game_add(&map, &pos, str, &mark))
            return (1);
    }
    display_map(map, pos);
    input();
    return (0);
}

int     game(char *str)
{
    clear();
    if (str == NULL)
        return (game_no_map());
    if (map_val(str) != 0)
        return (84);
    curs_set(false);
    keypad(stdscr, true);
    return (level(str, 0));
}
