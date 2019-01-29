/*
** EPITECH PROJECT, 2018
** menu
** File description:
** try not to segfault, good luck :)
*/

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/JoystickIdentification.h>

const char *name_map[5];

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
int     level(char *str, int sc);
int     nblig(char **map);
int     create_map(char *str);
int     load_map(char *str);
int     input();
int     game_add(char ***map, int **pos, char *str, int *mark);
void    reset(char ***map, int **pos, int *mark, char *str);

# define CND(x) (pos[x] + dir[ch - 1][x] > 0 && pos[x] + dir[ch - 1][x] <\
pos[2] - 1)

# define CND2 (pos[1] + dir[ch - 1][1] > 0 && pos[1] + dir[ch - 1][1] <\
pos[2] - 1 && pos[0] < my_strlen(map[pos[1] + dir[ch - 1][1]]) - 1)

# define CND3 (pos[0] + dir[ch - 1][0] > 0 && pos[0] + dir[ch - 1][0] <\
my_strlen(map[pos[1]]) - 1)

#endif
