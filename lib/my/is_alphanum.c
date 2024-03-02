/*
** EPITECH PROJECT, 2023
** help
** File description:
** is_alphanum.c
*/

#include "my.h"

int alphnum_two(char **argv, int i)
{
    for (int j = 0; argv[i][j] != '\0'; j++) {
        if (argv[1][0] < 65 || (argv[1][0] > 90 && argv[1][0] < 97)
        || argv[1][0] > 122) {
            my_printf("setenv: Variable name must begin with a letter.\n");
            return 1;
        }
        if (argv[i][j] < 48 || (argv[i][j] > 57 && argv[i][j] < 65)
        || (argv[1][0] > 90 && argv[1][0] < 97) || argv[i][j] > 122) {
            my_printf("setenv: Variable ");
            my_printf("name must contain alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

int is_alphanum(char **argv)
{
    if (!argv[1])
        return 84;
    if (alphnum_two(argv, 1) == 1)
        return 1;
    return 0;
}
