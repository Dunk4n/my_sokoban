/*
** EPITECH PROJECT, 2018
** editeur
** File description:
** try not to segfault, good luck :)
*/

#include <ncurses.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "menu.h"

char    **get_create_map(int n)
{
    char **map = malloc(sizeof(char*) * n);
    int i = 0;
    int j = 0;

    while (i < n) {
        map[i] = malloc(n + 1);
        map[i][n] = '\0';
        j = 0;
        while (j < n) {
            map[i][j] = (i > 0 && i < n - 1 && j > 0 && j < n - 1) ? ' ' : '#';
            j++;
        }
        i++;
    }
    return (map);
}

void    create(char **map, int nb)
{
    int fd = open("./create_map/custom_map", O_CREAT | O_RDWR | O_TRUNC);
    int i = -1;

    if (fd == -1)
        return ;
    while (++i < nb) {
        write(fd, map[i], nb);
        write(fd, "\n", 1);
    }
    close(fd);
}

int     input_edit(int ch, int *var, int *pos, char **map)
{
    int     dir[][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    char    str[] = "POX# ";

    if (ch == 6) {
        create(map, pos[2]);
        return (32);
    }
    if (ch >= 1 && ch <= 4) {
        pos[0] += (CND(0)) ? dir[ch - 1][0] : 0;
        pos[1] += (CND(1)) ? dir[ch - 1][1] : 0;
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

int     editor(int nb)
{
    char    **map = get_create_map(nb);
    char    dir = 0;
    int     pos[] = {1, 1, nb};
    int     var = 0;
    int     i = 0;

    while (dir != 7) {
        i = 0;
        while (i < nb)
            printw("%s\n", map[i++]);
        if (input_edit(dir, &var, pos, map) == 32)
            return (1);
        refresh();
        clear();
        dir = input();
    }
    return (0);
}

int     create_map(char *str)
{
    char nb[] = "  ";
    int  cnd = 263;

    (void)str;
    while (cnd == 263) {
        clear();
        nb[0] = getch();
        printw("%c", nb[0]);
        nb[1] = getch();
        printw("%c", nb[1]);
        cnd = getch();
        if (my_getnbr(nb) < 5 || my_getnbr(nb) > 40)
            cnd = 263;
    }
    clear();
    editor(my_getnbr(nb));
    refresh();
    return (0);
}
