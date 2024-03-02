/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** to_arr.c
*/
#include <string.h>
#include "my.h"

vars_t *var_ctor(void)
{
    vars_t *var = malloc(sizeof(vars_t));

    var->i = 0;
    var->j = 0;
    var->k = 0;
    return var;
}

char **conditions(char **arr, char *tmp, vars_t *var)
{
    if (tmp[var->k] != '"')
        for (var->k; tmp[var->k] != ' ' && tmp[var->k] != '\0'
        && tmp[var->k] != '\n' && tmp[var->k] != 9; var->k++) {
            arr[var->i][var->j] = tmp[var->k];
            var->j++;
        }
    if (tmp[var->k] == '"') {
        var->k++;
        while (tmp[var->k] != '"' && tmp[var->k] != '\0') {
            arr[var->i][var->j] = tmp[var->k];
            var->j++;
            var->k++;
        }
        var->k++;
    }
    return arr;
}

char **str_arr(char *input)
{
    char *tmp = my_strdup(input);
    int rows = how_many_rows_str(tmp);
    char **arr = malloc(sizeof(char *) * (rows + 3));
    vars_t *var = var_ctor();

    while (tmp[var->k] != '\0') {
        while (tmp[var->k] == ' ' || tmp[var->k] == '\n' || tmp[var->k] == 9)
            var->k++;
        arr[var->i] = malloc(sizeof(char) * (my_strlenn(tmp) + 1));
        arr = conditions(arr, tmp, var);
        arr[var->i][var->j] = '\0';
        var->i++;
        var->j = 0;
        while (tmp[var->k] == ' ' || tmp[var->k] == '\n' || tmp[var->k] == 9)
            var->k++;
    }
    arr[var->i] = NULL;
    free(tmp);
    return arr;
}
