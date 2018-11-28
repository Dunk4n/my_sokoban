/*
** EPITECH PROJECT, 2018
** src/map
** File description:
** try not to segfault, good luck :)
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "menu.h"

char    **get_map(char *str)
{
    struct stat st;
    char        *buff;
    int         fd = 0;
    int         size = 0;
    char        **map;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return (NULL);
    stat(str, &st);
    buff = malloc(st.st_size + 1);
    size = read(fd, buff, st.st_size);
    buff[size] = '\0';
    close(fd);
    map = my_str_to_word_array(buff, '\n');
    free(buff);
    return (map);
}

int     *player(char *str)
{
    char **map = get_map(str);
    int  *player = malloc(sizeof(int) * 2);
    int  bol = 0;

    player[0] = 0;
    player[1] = 0;
    while (map[player[0]] != 0 && bol == 0) {
        player[1] = 0;
        while (map[player[0]][player[1]] != '\0' && bol == 0) {
            bol += (map[player[0]][player[1]] == 'P') ? 1 : 0;
            player[1]++;
        }
        player[0]++;
    }
    player[0]--;
    player[1]--;
    return (player);
}

int     nb_mark(char *str)
{
    char **map = get_map(str);
    int  i = 0;
    int  j = 0;
    int  nb = 0;

    while (map[i] != 0) {
        j = 0;
        while (map[i][j] != '\0') {
            nb += (map[i][j] == 'O') ? 1 : 0;
            j++;
        }
        i++;
    }
    return (nb);
}
