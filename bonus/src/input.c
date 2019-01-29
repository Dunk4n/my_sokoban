/*
** EPITECH PROJECT, 2018
** input
** File description:
** try not to segfault, good luck :)
*/

#include <ncurses.h>
#include "my.h"
#include "menu.h"

int     input1(int *chj1)
{
    if (sfJoystick_getAxisPosition(0, sfJoystickY) == 100)
        *chj1 = 3;
    if (sfJoystick_getAxisPosition(0, sfJoystickY) == -100)
        *chj1 = 1;
    if (sfJoystick_getAxisPosition(0, sfJoystickX) == 100)
        *chj1 = 4;
    if (sfJoystick_getAxisPosition(0, sfJoystickX) == -100)
        *chj1 = 2;
    if (sfJoystick_getAxisPosition(0, sfJoystickX) == 0 &&
sfJoystick_getAxisPosition(0, sfJoystickY) == 0 && *chj1 != 0)
        return (1);
    return (0);
}

int     input2(int *chb)
{
    if (sfJoystick_isButtonPressed(0, 0))
        *chb = 5;
    if (sfJoystick_isButtonPressed(0, 1))
        *chb = 6;
    if (sfJoystick_isButtonPressed(0, 2))
        *chb = 7;
    if (sfJoystick_isButtonPressed(0, 3))
        *chb = 8;
    if (*chb != 0 && sfJoystick_isButtonPressed(0, 0) == 0 &&
sfJoystick_isButtonPressed(0, 1) == 0 && sfJoystick_isButtonPressed(0, 2) == 0
&& sfJoystick_isButtonPressed(0, 3) == 0)
        return (1);
    return (0);
}

int     input3(int *chj2)
{
    if (sfJoystick_getAxisPosition(0, sfJoystickV) == 100)
        *chj2 = 9;
    if (sfJoystick_getAxisPosition(0, sfJoystickV) == -100)
        *chj2 = 10;
    if (sfJoystick_getAxisPosition(0, sfJoystickU) == 0 &&
sfJoystick_getAxisPosition(0, sfJoystickV) == 0 && *chj2 != 0)
        return (1);
    return (0);
}

int     input()
{
    int chj1 = 0;
    int chb = 0;
    int chj2 = 0;

    while (1) {
        sfJoystick_update();
        if (input1(&chj1) == 1)
            return (chj1);
        if (input2(&chb) == 1)
            return (chb);
        if (input3(&chj2) == 1)
            return (chj2);
    }
    return (0);
}
