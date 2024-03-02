/*
** EPITECH PROJECT, 2023
** radar
** File description:
** str_to_float.c
*/

#include <math.h>
#include <stdio.h>

// Uses stdio lib
float str_to_float_lib(char *str)
{
    float result = 0.0;
    int tmp = sscanf(str, "%f", &result);

    return result;
}

// Does not use stdio lib
float str_to_float(char *str)
{
    float result = 0.0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10.0f + (str[i] - '0');
        }
    }
    return result;
}
