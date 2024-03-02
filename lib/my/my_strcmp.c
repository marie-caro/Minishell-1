/*
** EPITECH PROJECT, 2023
** strcmp
** File description:
** The strcmp() function compares the two strings s1 and s2.
** The comparison is done using unsigned characters.
** strcmp() returns an integer indicating the result
** of the comparison, as follows:
** - 0, if the s1 and s2 are equal;
** - a negative value if s1 is less than s2;
** - a positive value if s1 is greater than s2.
*/
#include <stdbool.h>
#include <stdio.h>
#include "my.h"


// Not actual equivalent to strcmp -> just tells if exactly same string
bool my_strcmp(char *str, char *str2)
{
    if (my_strlenn(str) != my_strlenn(str2))
        return false;
    for (int i = 0; i < my_strlenn(str); i++) {
        if (str[i] != str2[i]) {
            return false;
        }
    }
    return true;
}
