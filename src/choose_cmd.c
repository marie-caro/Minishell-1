/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** choose_cmd.c
*/

#include "../include/my.h"
#include <sys/wait.h>

static builtin_t list[] = {
    {"cd", &complete_d},
    {"env", &complete_env},
    {"setenv", &complete_setenv},
    {"unsetenv", &complete_unsetenv},
    {"exit", &complete_exit},
    {NULL, NULL}
};

void if_coredmp(int status)
{
    if (WCOREDUMP(status))
        my_puterror(" (core dumped)");
    my_printf("\n");
}

void continue_parent(pid_t cpid, int status, pid_t w, int result)
{
    w = waitpid(cpid, &status, WUNTRACED);
    while (!WIFEXITED(status) && !WIFSIGNALED(status))
        w = waitpid(cpid, &status, WUNTRACED);
    result = WEXITSTATUS(status);
    if (WIFEXITED(status))
        result = WIFEXITED(status);
    if (!WIFEXITED(status) && WIFSIGNALED(status)) {
        result = WTERMSIG(status);
        my_puterror(strsignal(result));
        if_coredmp(status);
    }
    if (!WIFEXITED(status) && !WIFSIGNALED(status) && WIFSTOPPED(status)) {
        result = WSTOPSIG(status);
        my_puterror(strsignal(result));
        if_coredmp(status);
    }
}

void is_bin_notexe(void)
{
    if (errno == ENOEXEC)
        my_puterror(" Wrong Architecture.");
}

static int is_slash(char *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '/' && access(str, F_OK) != -1) {
            my_printf(": %s", strerror(errno));
            my_puterror(".");
            is_bin_notexe();
            my_putcharn('\n');
            return 0;
        }
    my_puterror(": Command not found.\n");
    return 1;
}

static void process(char *path, shell_t *shell, char *input, char **argv)
{
    pid_t w;
    int status;
    pid_t cpid;
    int result = 0;

    cpid = fork();
    if (cpid == 0) {
        result = execve(path, argv, shell->env);
        if (result == -1) {
            my_puterror(argv[0]);
            is_slash(argv[0]);
            my_puterror("[marie@");
            my_puterror(shell->current);
            my_puterror("]$ ");
            shell->result = 1;
        }
    } else
        continue_parent(cpid, status, w, result);
}

static int cases(char *input)
{
    if (input[0] == '/')
        return 2;
    if (input[0] == '.')
        return 3;
    for (int i = 1; input[i] != '\0' && input[i] != ' '; i++)
        if (input[i] == '/')
            return 1;
    return 4;
}

int how_many_words(char *input)
{
    int count = 0;
    int v = 0;
    int k = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ')
            count++;
        if (input[i] == '-')
            count--;
    }
    for (v; input[v] != ' ' && input[v] != '\0'; v++);
    for (k = v; input[k] != '\0'; k++)
        if (input[k] == '/')
            count--;
    count++;
    return count;
}

static void exe_cmd(shell_t *shell, char *input, char **argv)
{
    char *cmd = argv[0];
    int words = how_many_words(input);

    if ((cases(input) == 1 && words == 2) || cases(input) == 4)
        process(find_exe(cmd, shell->env, argv), shell, input, argv);
    if ((cases(input) == 1 && words == 1) || cases(input) == 2
    || cases(input) == 3)
        process(cmd, shell, input, argv);
    free(cmd);
}

void scenario(char *input, int ac, shell_t *shell)
{
    int i = 0;
    char **argv = str_arr(input);

    for (int k = 0; k < 5; k++) {
        if (my_strcmp(argv[0], list[k].cmd)) {
            list[k].output(argv, shell);
            return;
        }
    }
    exe_cmd(shell, input, argv);
    free(argv);
}
