/*
** EPITECH PROJECT, 2023
** organized
** File description:
** compare.c
*/
#include "my.h"

int compare_function(void *data, void *ref)
{
    if (my_strcmp((char *) data, (char *) ref) == 1) {
        return 1;
    }
    return 0;
}
