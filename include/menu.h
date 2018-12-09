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
int     size_map(char **map);
int     map_val(char *str);
int     nblig(char **map);
int     *player(char *str);
int     nb_mark(char *str);
void    step(char **map, int *pos, int dir, int *mark);
int     out(char **map, int *pos, int dir);
void    char_map(char **map, int *pos, int i, int j);
void    display_map(char **map, int *pos);
int     if_box(char **map, int i, int j);
int     block(char **map);
void    reset(char ***map, int **pos, int *mark, char *str);
int     level(char *str);

#endif
