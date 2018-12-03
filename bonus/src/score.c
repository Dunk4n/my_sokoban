/*
** EPITECH PROJECT, 2018
** src/score
** File description:
** try not to segfault, good luck :)
*/

#include <ncurses.h>
#include <stdlib.h>
#include <fcntl.h>
#include "menu.h"
#include "my.h"

char    *my_itoa(int nb)
{
    int i = 0;
    int nbt = nb;
    char *tab;

    if (nb == 0)
        i = 1;
    while (nbt != 0) {
        nbt /= 10;
        i++;
    }
    tab = malloc(i + 1);
    tab[i] = '\0';
    while (i > 0) {
        tab[--i] = nb % 10 + '0';
        nb /= 10;
    }
    return (tab);
}

int     score(int sc)
{
    char    buff[4096];
    int     fd = open("./doc/scores", O_RDWR);
    int     size = 1;

    if (sc != -1) {
        if (sc > score(-1))
            write(fd, my_itoa(sc), my_strlen(my_itoa(sc)));
        return (-1);
    }
    if (fd == -1)
        return (-1);
    size = read(fd, buff, 4095);
    if (fd != 0)
        buff[size] = '\0';
    return (my_getnbr(buff));
    close(fd);
}

int     put_score(char *str)
{
    (void)str;
    clear();
    refresh();
    mvprintw(LINES / 2, COLS / 2 - my_strlen(my_itoa(score(-1)))
/ 2, my_itoa(score(-1)));
    getch();
    clear();
    refresh();
    return (1);
}
