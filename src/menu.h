/*
** EPITECH PROJECT, 2018
** menu
** File description:
** try not to segfault, good luck :)
*/

#ifndef MENU_H
#define MENU_H

const char *name_map[3];

void    menu();
int     score(int sc);
int     put_score();
int     nb_mark(char *str);
int     *player(char *str);
char    **get_map(char *str);
int     game(int ac, char **av);
void    display_map(char **map, int *pos);
void    direction(char **map, int *pos, int *mark, int dir);

#endif
