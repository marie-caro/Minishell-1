/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** ere
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"


void my_putcharn(char c)
{
    write(1, &c, 1);
}
