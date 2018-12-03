/*
** EPITECH PROJECT, 2018
** menu
** File description:
** try not to segfault, good luck :)
*/

#ifndef MENU_H
#define MENU_H

const char *name_map[3];

void    menu(char *str);
int     score(int sc);
int     put_score(char *str);
int     nb_mark(char *str);
int     *player(char *str);
char    **get_map(char *str);
int     game(char *str);
void    display_map(char **map, int *pos);
void    direction(char **map, int *pos, int *mark, int dir);
int     size_map(char **map);
int     map_val(char *str);
int     game_no_map();
int     level(char *str);
int     nblig(char **map);

#endif
