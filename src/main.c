/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main.c
*/
#include "../include/my.h"

char **cpy_arr(char **arr)
{
    int i = 0;
    int j = 0;
    int count = 0;
    char **my_arr;

    for (count; arr[count] != NULL; count++);
    my_arr = malloc(sizeof(char *) * (count + 1));
    for (i; arr[i] != NULL; i++) {
        my_arr[i] = malloc(sizeof(char) * (my_strlenn(arr[i]) + 1));
        for (j = 0; arr[i][j] != '\0'; j++)
            my_arr[i][j] = arr[i][j];
        my_arr[i][j] = '\0';
    }
    my_arr[i] = NULL;
    return my_arr;
}

shell_t *shell_ctor(char **env)
{
    int i = 0;
    shell_t *shell = malloc(sizeof(shell_t));
    int line = get_path(env, "OLDP");
    char *info = NULL;
    char cwd[1024];

    shell->env = cpy_arr(env);
    if (line != -1) {
        info = get_line(env, line);
        shell->old = malloc(sizeof(char) * (my_strlenn(info) + 1));
        for (int k = 0; info[i] != '\0'; i++) {
            shell->old[i] = info[k];
            k++;
        }
        shell->old[i] = '\0';
    }
    shell->current = my_strdup(getcwd(cwd, sizeof(cwd)));
    shell->exit = 0;
    shell->result = 1;
    return shell;
}

void update_pos(shell_t *shell)
{
    char cwd[1024];

    getcwd(cwd, sizeof(cwd));
    shell->current = my_strdup(cwd);
}

void my_frees(char *line, shell_t *shell)
{
    free(shell->current);
    for (int i = 0; shell->env[i] != NULL; i++)
        free(shell->env[i]);
    free(shell->env);
    free(shell->old);
    free(shell);
    free(line);
}

int main(int ac, char **av, char **env)
{
    char *line = NULL;
    size_t size = 0;
    shell_t *shell = shell_ctor(env);

    my_printf("[marie@%s]$ ", shell->current);
    while (1) {
        if (shell->result == 0)
            my_printf("[marie@%s]$ ", shell->current);
        shell->result = 0;
        if (getline(&line, &size, stdin) == -1) {
            my_printf("\n");
            return 0;
        }
        if (my_strcmp(line, "\n") != 1)
            scenario(line, ac, shell);
            update_pos(shell);
        if (shell->exit == 1)
            return 0;
    }
    my_frees(line, shell);
}
