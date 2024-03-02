/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my.h
*/

#pragma once
#include "../lib/my/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

typedef struct shell_s {
    char *old;
    char **env;
    char *current;
    int exit;
    int error;
    int result;
    int count;
} shell_t;

typedef struct var_s {
    int i;
    int j;
    int k;
    int v;
} var_t;

typedef struct builtin_s {
    char *cmd;
    void (*output)(char **argv, shell_t *shell);
} builtin_t;

char *find_exe(char *cmd, char **env, char **argv);
char *get_line(char **env, int count);
int get_path(char **env, char *name);
char **str_arr(char *input);

void complete_exit(char **argv, shell_t *shell);
void complete_d(char **argv, shell_t *shell);
void complete_env(char **argv, shell_t *shell);
void complete_setenv(char **argv, shell_t *shell);
void complete_unsetenv(char **argv, shell_t *shell);

void scenario(char *input, int ac, shell_t *shell);
