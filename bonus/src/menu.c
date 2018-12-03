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
    int (*fonc[])(char*) = {&game, &put_score, &quit};
    char *choi[] = {"play", "score", "quit"};
    int  i = 0;
    int  inc = 0;

    while (i < 3) {
        (i == *ch) ? attron(A_STANDOUT) : 0;
        mvprintw(LINES / 2 - 3 + i * 3,  COLS / 2 - my_strlen(choi[i]) / 2,
choi[i]);
        attroff(A_STANDOUT);
        i++;
    }
    inc = getch();
    if (inc == KEY_UP && *ch > 0)
        *ch -= 1;
    if (inc == KEY_DOWN && *ch < 2)
        *ch += 1;
    if (inc == 10)
        *res = fonc[*ch](str);
    //*res = (fonc[*ch](str) == 0 && *ch == 0) ? 0 : 1;
}

void    menu(char *str)
{
    int ch = 0;
    int res = 0;

    initscr();
    noecho();
    cbreak();
    //getmaxyx(stdscr, y_max, x_max);
    curs_set(false);
    keypad(stdscr, true);
    while (res != 10) {
        upchoices(&ch, &res, str);
        refresh();
        clear();
    }
    endwin();
}
