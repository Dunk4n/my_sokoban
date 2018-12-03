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
    int     cnt[] = {0, 0, 0, 0, 0};

    if (map == NULL)
        return (1);
    while (map[cnt[3]] != 0 && bol == 0) {
        cnt[4] = 0;
        while (map[cnt[3]][cnt[4]] != '\0' && bol == 0) {
            bol += (map[cnt[3]][cnt[4]] == ' ' || map[cnt[3]][cnt[4]] == '\n' ||
map[cnt[3]][cnt[4]] == '#' || map[cnt[3]][cnt[4]] == 'X' || map[cnt[3]][cnt[4]]
== 'O' || map[cnt[3]][cnt[4]] == 'P') ? 0 : 1;
            cnt[0] += ((map[cnt[3]][cnt[4]] == 'P') ? 1 : 0);
            cnt[1] += ((map[cnt[3]][cnt[4]] == 'X') ? 1 : 0);
            cnt[2] += ((map[cnt[3]][cnt[4]] == 'O') ? 1 : 0);
            cnt[4]++;
        }
        cnt[3]++;
    }
    return ((cnt[0] != 1 || cnt[1] < cnt[2] || cnt[2] == 0) ? 1 : bol);
}
