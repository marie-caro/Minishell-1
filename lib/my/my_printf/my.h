/*
** EPITECH PROJECT, 2023
** flags
** File description:
** minni printf flags
*/
#pragma once
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define ABS(a) ((a < 0) ? -a : a)

// My Printf
int my_printf(const char *restrict format, ...);
int part_two(const char *format, int i, va_list list);
int format_found_l(const char *format, int i, va_list list);
int format_found_h(const char *format, int i, va_list list);

// Output results
int print_char(va_list list, void *);
int my_putchar(char c);
int print_char_spec(va_list list, void *);

int print_str(va_list list, void *);
int my_putstr(char const *str);

int print_nbr(va_list list, void *);
int my_put_nbr(long long int nb);
int print_format_l(va_list list, void *);
int my_put_nbr_format_l(long int nb);
int print_format_h(va_list list, void *);
int my_put_nbr_format_h(short int nb);

int my_print_float(va_list list, void *);
int my_put_float(double nb, void *);

int print_hexoct(va_list list, void *);
int my_print_all(va_list list, void *, int);
int my_put_all(long long int nb, char conv, int stock);
int my_puthex_p(unsigned long long nb, char conv);
int my_puthex(long long int nb, char conv);

int my_print_scientific(va_list list, void *);
int my_put_scientific(double nb, void *);
int puissance(int count);
int my_output(int w, int h, int j, int b);

int my_print_scientific_maj(va_list list, void *);
int my_put_scientific_maj(double nb, void *);
int puissance_maj(int count);
int my_output_maj(int w, int h, int j, int b);

int my_put_p(void *str);
int my_print_p(va_list list, void *flag);

// Other
int my_strlen(char const *str);
int my_int_str_rec(int nb, char *str);
char *my_int_str(int nb);
int my_print_plus(va_list list);
int if_flag(char *str, int *i, long long);
int print_hexa_l(va_list list, void *);
int my_put_hexa_l(long long nb, char conv);
int print_hexa_h(va_list list, void *);
int my_put_hexa_h(long long nb, char conv);
int my_put_alternate(long long nb, char flag);


typedef struct struct_output {
    int(*output)(va_list, void *);
    char flags;
}struct_t;
