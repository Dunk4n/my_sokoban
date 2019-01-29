/*
** EPITECH PROJECT, 2018
** menu
** File description:
** try not to segfault, good luck :)
*/

#include <ncurses.h>
#include "menu.h"
#include "my.h"

int     quit(char *str)
{
    (void)str;
    return (10);
}

void    upchoices(int *ch, int *res, char *str)
{
    int (*fonc[])(char*) = {&game, &put_score, &create_map, &load_map, &quit};
    char *choi[] = {"Play", "Score", "editor", "loader","Quit"};
    int  i = 0;
    int  inc = 0;

    while (i < 5) {
        (i == *ch) ? attron(A_STANDOUT) : 0;
        mvprintw(LINES / 2 - 9 + i * 3,  COLS / 2 - my_strlen(choi[i]) / 2,
choi[i]);
        attroff(A_STANDOUT);
        i++;
    }
    refresh();
    inc = input();
    if (inc == 1 && *ch > 0)
        *ch -= 1;
    if (inc == 3 && *ch < 4)
        *ch += 1;
    if (inc == 5)
        *res = fonc[*ch](str);
}

void    menu(char *str)
{
    int ch = 0;
    int res = 0;

    initscr();
    noecho();
    cbreak();
    curs_set(false);
    keypad(stdscr, true);
    while (res != 10) {
        upchoices(&ch, &res, str);
        clear();
    }
    endwin();
}
