/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** read_term.c
*/
#include "../include/my.h"

int open_dir(char *path)
{
    DIR *dirp;
    int i = 0;
    struct dirent *sd;

    dirp = opendir(path);
    if (dirp == NULL)
        return 84;
    sd = readdir(dirp);
    while (sd != NULL) {
        if (my_strcmp("ls", sd->d_name))
            return 0;
        sd = readdir(dirp);
    }
    closedir(dirp);
    return 1;
}

static int how_many(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':')
            count++;
    }
    return count;
}

static var_t *init_var(void)
{
    var_t *var = malloc(sizeof(var_t));

    var->i = 0;
    var->j = 0;
    var->k = 0;
    var->v = 0;
    return var;
}

static char **str_to_arr(var_t *var, char *str)
{
    int count = how_many(str) + 1;
    char **arr = malloc(sizeof(char *) * (count + 1));

    arr[0] = malloc(sizeof(char) * 75);
    for (; str[var->i] != '\0'; var->i++) {
        if (str[var->i] == ':') {
            arr[var->k][var->v] = '\0';
            var->k++;
            arr[var->k] = malloc(sizeof(char) * 75);
            var->v = 0;
            var->i++;
        }
        if (var->k == 0 && var->v == 0)
            var->i = 5;
        arr[var->k][var->v] = str[var->i];
        var->v++;
    }
    var->k++;
    arr[var->k] = NULL;
    return arr;
}

char *my_memset(char *name)
{
    int i = 0;
    char *tmp = malloc(sizeof(char) * (my_strlenn(name) + 1));

    for (i; i < my_strlenn(name); i++)
        tmp[i] = '0';
    tmp[i] = '\0';
    return tmp;
}

int get_path(char **env, char *name)
{
    int i = 0;
    char *tmp = malloc(sizeof(char) * 10);

    if (!name)
        return -1;
    tmp = my_memset(name);
    for (; env[i] != NULL; i++) {
        for (int j = 0; j < my_strlenn(name); j++)
            tmp[j] = env[i][j];
        if (my_strcmp(tmp, name) == 1) {
            free(tmp);
            return i;
        }
    }
    free(tmp);
    return -1;
}

char *get_line(char **env, int count)
{
    int i = 0;
    int len = my_strlenn(env[count]);
    char *tmp = malloc(sizeof(char) * (len + 1));

    for (; i < len; i++) {
        tmp[i] = env[count][i];
    }
    tmp[i] = '\0';
    return tmp;
}

static void my_free(char **arr, char *info, char **my_arr, char *c_cmd)
{
    free(info);
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
    for (int i = 0; my_arr[i] != NULL; i++)
        free(my_arr[i]);
    free(my_arr);
    free(c_cmd);
}

char *find_exe(char *cmd, char **env, char **argv)
{
    var_t *var = init_var();
    int count = get_path(env, "PATH");
    char *info = NULL;
    int v = 0;
    char **arr;
    char **my_arr = malloc(sizeof(char *) * 50);
    char *c_cmd = my_strcat("/", cmd);

    if (count == -1)
        return NULL;
    info = get_line(env, count);
    v = how_many(info);
    arr = str_to_arr(var, info);
    for (int i = 0; arr[i] != NULL; i++)
        if (open_dir(arr[i]) == 0)
            return my_strcat(arr[i], c_cmd);
    free(var);
    my_free(arr, info, my_arr, c_cmd);
    return NULL;
}
