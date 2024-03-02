/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** gfdsa
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"



static struct_t var[] = {
    {&print_char, 'c'},
    {&print_str, 's'},
    {&print_nbr, 'i'},
    {&print_nbr, 'd'},
    {&print_char_spec, '%'},
    {&print_hexoct, 'u'},
    {&print_hexoct, 'x'},
    {&print_hexoct, 'X'},
    {&print_hexoct, 'o'},
    {&my_print_float, 'f'},
    {&my_print_float, 'F'},
    {&my_print_scientific, 'e'},
    {&my_print_scientific_maj, 'E'},
    {&my_print_p, 'p'},
    {NULL, '\0'}
};

int part_two(const char *format, int i, va_list list)
{
    int stock = 0;
    int count = 0;

    for (int j = 0; j < 14; j++) {
        if (format[i] == var[j].flags) {
            stock += var[j].output(list, (void *) &var[j].flags);
        }
        if (format[i] == ' ' && format[i + 1] == var[j].flags) {
            stock += var[j].output(list, (void *) &var[j].flags);
        }
        if (format[i] != var[j].flags)
            count++;
    }
    if (count == 14) {
        stock += my_putchar(format[i - 1]);
        stock += my_putchar(format[i]);
    }
    return stock;
}

char *copy_format(char const *restrict format)
{
    int j = 0;
    int len2 = my_strlen(format);
    char *str = malloc(sizeof(char) * (len2 + 1));

    if (str == NULL)
        return NULL;
    for (int k = 0; k < len2; k++)
        str[k] = 0;
    for (int i = 0; i <= len2; i++) {
        if (i == 0)
            str[j] = format[i];
        if (format[i] == ' ' && format[i - 1] == '%' && format[i - 2] != '%')
            i++;
        str[j] = format[i];
        j++;
    }
    return str;
}

int percent_not_found(char *str, int i)
{
    int stock = 0;

    if (str[i] != '%')
        stock += my_putchar(str[i]);
    return stock;
}

int percent_found(char *str, int *i, va_list list)
{
    int stock = 0;

    if (str[*i] == 'l') {
        stock += format_found_l(str, *i, list);
        (*i)++;
    }
    if (str[*i] == 'h') {
        stock += format_found_h(str, *i, list);
        (*i)++;
    }
    if ((str[*i] != 'h' && str[*i] != 'l') &&
        (*i > 0 && str[*i - 1] != 'h' && str[*i - 1] != 'l')) {
        stock += part_two(str, *i, list);
    }
    return stock;
}

int my_printf(const char *restrict format, ...)
{
    int stock = 0;
    va_list list;
    va_list copy;
    char *str = copy_format(format);
    int len = my_strlen(str);

    va_start(list, format);
    for (int i = 0; i < len; i++) {
        stock += percent_not_found(str, i);
        if (str[i] == '%') {
            va_copy(copy, list);
            stock += if_flag(str, &i, va_arg(copy, long long));
            i++;
            stock += percent_found(str, &i, list);
            va_end(copy);
        }
    }
    va_end(list);
    return stock;
}
