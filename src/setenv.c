/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** env.c
*/

#include "../include/my.h"

static char **create_var(char **argv, shell_t *shell)
{
    int i = 0;
    int j = 0;
    char **new;
    char *tmp = NULL;
    int len = my_strlenn(argv[1]) + my_strlenn(argv[2]) + 3;

    for (; shell->env[j] != NULL; j++);
    new = malloc(sizeof(char *) * (j + 2));
    for (i = 0; i < j; i++)
        new[i] = my_strdup(shell->env[i]);
    new[i] = malloc(sizeof(char) * (len));
    tmp = my_strcat(argv[1], "=");
    new[i] = my_strcat(tmp, argv[2]);
    new[i + 1] = malloc(sizeof(char) * (len));
    new[i + 1] = NULL;
    return new;
}

static char **create_var_empty(char **argv, shell_t *shell)
{
    int i = 0;
    int j = 0;
    char **new;
    char *tmp = NULL;
    int len = my_strlenn(argv[1]) + 3;

    for (; shell->env[j] != NULL; j++);
    new = malloc(sizeof(char *) * (j + 2));
    for (i = 0; i < j; i++)
        new[i] = my_strdup(shell->env[i]);
    new[i] = malloc(sizeof(char) * (len));
    new[i] = my_strcat(argv[1], "=");
    new[i + 1] = malloc(sizeof(char) * (len));
    new[i + 1] = NULL;
    return new;
}

static char **change_var(char **argv, shell_t *shell, char *info, int count)
{
    int len = 0;

    if (!argv[2])
        return shell->env;
    len = my_strlenn(argv[1]) + my_strlenn(argv[2]) + 3;
    free(shell->env[count]);
    shell->env[count] = malloc(sizeof(char) * (len));
    shell->env[count] = my_strcat(argv[1], "=");
    shell->env[count] = my_strcat(shell->env[count], argv[2]);
    return shell->env;
}

int count_args(char **argv)
{
    int i = 0;

    for (i; argv[i] != NULL; i++);
    return i;
}

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
}

void change_env(char *info, shell_t *shell, int count, char **argv)
{
    info = get_line(shell->env, count);
    change_var(argv, shell, info, count);
}

void complete_setenv(char **argv, shell_t *shell)
{
    char *info = NULL;
    int count = 0;
    int i = count_args(argv);

    if (i == 1)
        print_env(shell->env);
    if (is_alphanum(argv) == 1)
        return;
    if (i == 2 || (i == 3 && argv[1]))
        count = get_path(shell->env, argv[1]);
    if (count == -1) {
        if (i == 2)
            shell->env = create_var_empty(argv, shell);
        if (i == 3)
            shell->env = create_var(argv, shell);
        return;
    }
    if (i > 3)
        return;
    change_env(info, shell, count, argv);
}
