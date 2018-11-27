/*
** EPITECH PROJECT, 2018
** direction
** File description:
** try not to segfault, good luck :)
*/

#include <ncurses.h>
#include "my.h"
#include "menu.h"

void    char_map(char **map, int *pos, int i, int j)
{
    if (pos[0] == i && pos[1] == j)
        printw("%c", 'P');
    else if (map[i][j] == '@')
        printw("%c", 'X');
    else
        printw("%c", map[i][j]);
}

void    display_map(char **map, int *pos)
{
    int i = 0;
    int j = 0;

    while (map[i] != 0) {
        j = 0;
        while (map[i][j] != '\0') {
            char_map(map, pos, i, j);
            j++;
        }
        printw("%c", '\n');
        i++;
    }
}

void    step(char **map, int *pos, int dir)
{
    int cd[][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    pos[0] += cd[dir][0];
    pos[1] += cd[dir][1];
    map[pos[0]][pos[1]] = ' ';
}

void    direction(char **map, int *pos, int *mark, int dir)
{
    int cd[][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    if (map[pos[0] + cd[dir][0]][pos[1] + cd[dir][1]] == 'X') {
        if (map[pos[0] + (cd[dir][0] * 2)][pos[1] + (cd[dir][1] * 2)] == ' ') {
            step(map, pos, dir);
            map[pos[0] + cd[dir][0]][pos[1] + cd[dir][1]] = 'X';
            return ;
        }
        if (map[pos[0] + (cd[dir][0] * 2)][pos[1] + (cd[dir][1] * 2)] == 'O') {
            step(map, pos, dir);
            map[pos[0]][pos[1]] = ' ';
            *mark -= 1;
            map[pos[0] + cd[dir][0]][pos[1] + cd[dir][1]] = '@';
            return ;
        }
    }
    if (map[pos[0] + cd[dir][0]][pos[1] + cd[dir][1]] == ' ' ||
map[pos[0] + cd[dir][0]][pos[1] + cd[dir][1]] == 'O') {
        pos[0] += cd[dir][0];
        pos[1] += cd[dir][1];
    }
}
