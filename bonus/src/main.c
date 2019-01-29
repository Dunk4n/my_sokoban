/*
** EPITECH PROJECT, 2018
** main
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include "my.h"
#include "menu.h"

const char *name_map[5] = {"map/map1", "map/map2", "map/map3", "map/map4",
"map/map5"};

int     main(int ac, char **av)
{
    /*while (1) {
        sfJoystick_update();
        if (sfJoystick_isConnected(0))
            printf("@WERTYU\n");
        printf("%f\n", sfJoystick_getAxisPosition(0, sfJoystickX));
        printf("%f\n", sfJoystick_getAxisPosition(0, sfJoystickY));
        printf("-----------\n");
        if (sfJoystick_isButtonPressed(0, 2))
            printf("QWERTYU\n");
    }*/
    if (ac > 2)
        return (84);
    if (ac == 2)
        menu(av[1]);
    if (ac == 1)
        menu(NULL);
    //input();
    return (0);
}
