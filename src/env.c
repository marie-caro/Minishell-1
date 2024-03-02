/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** env.c
*/

#include "../include/my.h"

void complete_env(char **argv, shell_t *shell)
{
    int i = 0;

    for (i; argv[i] != NULL; i++);
    if (i != 1)
        return;
    for (int i = 0; shell->env[i] != NULL; i++)
        my_printf("%s\n", shell->env[i]);
}
