/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** wdfvb
*/

#pragma once
#include <errno.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct vars_s {
    int i;
    int j;
    int k;
    int v;
} vars_t;

//##### Basic #############################################################//
void my_putcharn(char c);
int my_strlenn(char *str);
int my_put_nbr(long long int nb);
int my_put_nbr_rec(long long int nb, int a);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char *src);
bool my_strcmp(char *s1, char *s2);
char *my_strdup(char *src);
char *my_strncat(char *dest, char *src, int nb);
char *my_strcat(char *dst, char *src);
char *my_int_to_str(long long int nb);
int compare_function(void *data, void *ref);
int how_many_rows_file(char *filepath);
int how_many_rows_str(char *buffer);
char **read_file(int ac, char **av);
float str_to_float(char *str);
float str_to_float_lib(char *str);
char **read_file_noarg(char *filepath);
int my_get_nbr(char *str);
char *my_revert(char *str);
char *to_bin(int num);
char **load_to_arr(char *buffer);
char **load_to_arr(char *buffer);
char **str_arr(char *input);
int my_putchar_error(char c);
int my_puterror(char *str);
int is_alphanum(char **argv);

//##### Printf #############################################################//

#define ABS(a) ((a < 0) ? -a : a)

// My Printf
int my_printf(const char *restrict format, ...);
int part_two(const char *format, int i, va_list list);
int format_found_l(const char *format, int i, va_list list);
int format_found_h(const char *format, int i, va_list list);

// Output results
int print_char(va_list list, void *);
int print_char_spec(va_list list, void *);

int print_str(va_list list, void *);

int print_nbr(va_list list, void *);
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
