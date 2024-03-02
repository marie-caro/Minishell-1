/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_strncat.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"


char *my_strncat(char *dest, char *src, int nb)
{
    int len_dest = my_strlenn(dest);
    int len_src = my_strlenn(src);
    char a;
    int j = 0;
    int i = 0;

    if (len_src < nb) {
        for (j; j < len_src; j++) {
            dest[len_dest + j] = src[j];
        }
        return (dest);
    }
    for (; i < nb; i++) {
        if (i < nb) {
            a = src[i];
            dest[len_dest + i] = a;
        }
    }
    dest[len_dest] = '\0';
    return (dest);
}
