/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** exit.c
*/

#include "../include/my.h"

void complete_exit(char **argv, shell_t *shell)
{
    (void *)argv;
    shell->exit = 1;
}
