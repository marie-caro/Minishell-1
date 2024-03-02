/*
** EPITECH PROJECT, 2023
** formats
** File description:
** ewd
*/
#include <stdio.h>
#include "my.h"



static struct_t var2[] = {
    {&print_format_l, 'i'},
    {&print_format_l, 'd'},
    {&print_hexa_l, 'x'},
    {&print_hexa_l, 'X'},
    {NULL, '\0'}
};

static struct_t var3[] = {
    {&print_format_h, 'i'},
    {&print_format_h, 'd'},
    {&print_hexa_h, 'x'},
    {&print_hexa_h, 'X'},
    {NULL, '\0'}
};

int format_found_l(const char *format, int i, va_list list)
{
    int stock = 0;
    int count = 0;

    for (int j = 0; j < 3; j++) {
        if (format[i + 1] == var2[j].flags) {
            stock += var2[j].output(list, (void *) &var2[j].flags);
        }
        if (format[i + 1] != var2[j].flags)
            count++;
    }
    if (count == 13) {
        stock += my_putchar(format[i]);
        stock += my_putchar(format[i + 1]);
    }
    return stock;
}

int format_found_h(const char *format, int i, va_list list)
{
    int stock = 0;
    int count = 0;

    for (int j = 0; j < 3; j++) {
        if (format[i + 1] == var3[j].flags) {
            stock += var3[j].output(list, (void *) &var3[j].flags);
        }
        if (format[i + 1] != var3[j].flags)
            count++;
    }
    if (count == 13) {
        stock += my_putchar(format[i]);
        stock += my_putchar(format[i + 1]);
    }
    return stock;
}
