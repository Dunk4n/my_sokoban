/*
** EPITECH PROJECT, 2018
** loader
** File description:
** try not to segfault, good luck :)
*/

#include <ncurses.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "menu.h"

void    create_load(char **map, int nb)
{
    int fd = open("./create_map/custom_map", O_RDWR);
    int i = -1;

    if (fd == -1)
        return ;
    while (++i < nb) {
        write(fd, map[i], my_strlen(map[i]));
        write(fd, "\n", 1);
    }
}

int     input_load(int ch, int *var, int *pos, char **map)
{
    int     dir[][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    char    str[] = "POX# ";

    if (ch == 6) {
        create_load(map, pos[2]);
        return (32);
    }
    if (ch >= 1 && ch <= 4) {
        pos[0] += (CND3) ? dir[ch - 1][0] : 0;
        pos[1] += (CND2) ? dir[ch - 1][1] : 0;
    }
    if (ch == 5)
        map[pos[1]][pos[0]] = str[*var];
    if (ch == 9)
        *var = ((*var > 0) ? ((*var) - 1) : (my_strlen(str) - 1));
    if (ch == 10)
        *var = ((*var < 4 ) ? ((*var) + 1) : 0);
    mvprintw(pos[1], pos[0], "%c", str[*var]);
    return (0);
}

int     editor_load(char *str)
{
    char    **map = get_map(str);
    char    dir = 0;
    int     pos[] = {1, 1, 0};
    int     var = 0;
    int     i = 0;

    if (map == NULL)
        return (1);
    while (map[pos[2]] != 0)
        pos[2]++;
    while (dir != 7) {
        i = 0;
        while (map[i] != 0)
            printw("%s\n", map[i++]);
        if (input_load(dir, &var, pos, map) == 32)
            return (1);
        refresh();
        clear();
        dir = input();
    }
    return (0);
}

int     load_map(char *str)
{
    if (str == NULL)
        return (0);
    clear();
    editor_load(str);
    refresh();
    return (0);
}
