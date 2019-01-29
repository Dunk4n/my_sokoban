/*
** EPITECH PROJECT, 2018
** map_val
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include "my.h"
#include "menu.h"

int     map_val(char *str)
{
    char    **map = get_map(str);
    int     bol = 0;
    int     i = 0;
    int     j = 0;

    if (map == NULL)
        return (1);
    while (map[i] != 0 && bol == 0) {
        j = 0;
        while (map[i][j] != '\0' && bol == 0) {
            bol += (map[i][j] == ' ' || map[i][j] == '\n' || map[i][j] == '#' ||
map[i][j] == 'X' || map[i][j] == 'O' || map[i][j] == 'P') ? 0 : 1;
            j++;
        }
        i++;
    }
    return (bol);
}
