/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Write a function that displays, one-by-one, the characters of a string.
** The address of the string’s first character will be found in
** the pointer passed as a parameter to the function
*/
#include "my.h"

int my_putstrn(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putcharn(str[i]);
    }
    return 0;
}

int my_puterror(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar_error(str[i]);
    }
    return 0;
}
