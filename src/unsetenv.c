/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** env.c
*/

#include "../include/my.h"

static char **delete_var(char **argv, shell_t *shell, int count)
{
    int i = 0;
    int len = 0;
    int k = 0;
    char **new;

    for (; shell->env[len] != NULL; len++);
    new = malloc(sizeof(char *) * (len));
    for (i = 0; shell->env[i] != NULL; i++) {
        new[k] = my_strdup(shell->env[i]);
        if (i + 1 == count)
            i++;
        k++;
    }
    new[k] = NULL;
    return new;
}

void find_delete(int count, char **argv, shell_t *shell)
{
    if (count != -1) {
        shell->env = delete_var(argv, shell, count);
        return;
    }
}

void complete_unsetenv(char **argv, shell_t *shell)
{
    int count = 0;
    char *info = NULL;
    int i = 0;

    for (i; argv[i] != NULL; i++);
    if (i == 1)
        return;
    for (int j = 1; argv[j] != NULL; j++) {
        if (argv[j]) {
            count = get_path(shell->env, argv[j]);
            find_delete(count, argv, shell);
        }
    }
    free(info);
}
