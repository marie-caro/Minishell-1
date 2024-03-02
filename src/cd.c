/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** cd.c
*/

#include "../include/my.h"

void manage_dash(char **argv, shell_t *shell)
{
    if (shell->old) {
        my_printf("%s\n", shell->old);
        chdir(shell->old);
    }
}

int manage_wave(char **argv, shell_t *shell)
{
    int k = 0;
    int line = get_path(shell->env, "HOME");
    char *path = NULL;
    char *tmp = NULL;

    if (line == -1)
        return -1;
    path = get_line(shell->env, line);
    tmp = malloc(sizeof(char) * (my_strlenn(path) - 4));
    for (int i = 5; path[i] != '\0'; i++) {
        tmp[k] = path[i];
        k++;
    }
    tmp[k] = '\0';
    chdir(tmp);
    return 0;
}

void complete_d(char **argv, shell_t *shell)
{
    char cwd[1024];
    struct stat sb;

    getcwd(cwd, sizeof(cwd));
    if (argv[1] && argv[1][0] != '-' && argv[1][0] != '~') {
        stat(argv[1], &sb);
        if (!S_ISDIR(sb.st_mode) && access(argv[1], F_OK) != -1) {
            my_puterror(my_strcat(argv[1], ": Not a directory.\n"));
            return;
        }
        if (chdir(argv[1]) == -1 && access(argv[1], F_OK) == -1)
            my_puterror(my_strcat(argv[1], ": No such file or directory.\n"));
    }
    if (argv[1] && argv[1][0] == '-')
        manage_dash(argv, shell);
    if ((argv[1] && argv[1][0] == '~') || !argv[1])
        if (manage_wave(argv, shell) == -1)
            return;
    shell->old = my_strdup(cwd);
    return;
}
