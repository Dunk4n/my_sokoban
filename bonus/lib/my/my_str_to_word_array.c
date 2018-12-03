/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_split_whites_spaces
*/

#include <stdlib.h>

static int     charword(char const *str, int n, int nl, char ch)
{
    int i = 0;
    int sp = 1;
    int nb = 0;
    int let = 0;

    while (str[i] != '\0') {
        if (sp == 1 && str[i] != ch) {
            sp = 0;
            nb++;
        }
        sp = (str[i] == ch) ? 1 : 0;
        let += (str[i] != ch && nb == n) ? 1 : 0;
        if (let == nl)
            return (str[i]);
        i++;
    }
    return ('\0');
}

static int     nbchar(char const *str, int n, char ch)
{
    int i = 0;
    int sp = 1;
    int nb = 0;
    int let = 0;

    while (str[i] != '\0') {
        if (sp == 1 && str[i] != ch) {
            sp = 0;
            nb++;
        }
        sp = (str[i] == ch) ? 1 : 0;
        let += (str[i] != ch && nb == n) ? 1 : 0;
        i++;
    }
    return (let);
}

static int     nbword(char const *str, char ch)
{
    int i = 0;
    int sp = 1;
    int nb = 0;

    while (str[i] != '\0') {
        if (sp == 1 && str[i] != ch) {
            sp = 0;
            nb++;
        }
        sp = (str[i] == ch) ? 1 : 0;
        i++;
    }
    return (nb);
}

char    **my_str_to_word_array(char const *str, char ch)
{
    int i = 1;
    int j = 1;
    char **tab = malloc(sizeof(char*) * (nbword(str, ch) + 1));

    while (i - 1 < nbword(str, ch)) {
        tab[i - 1] = malloc(nbchar(str, i, ch));
        j = 1;
        while (j - 1 < nbchar(str, i, ch)) {
            tab[i - 1][j - 1] = charword(str, i, j, ch);
            j++;
        }
        tab[i - 1][j - 1] = '\0';
        i++;
    }
    tab[i - 1] = 0;
    return (tab);
}
