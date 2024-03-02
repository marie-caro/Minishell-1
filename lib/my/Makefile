##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## 1. copy the build library into lib/
## implement the clean rule
##

SRC = 	my_putchar.c\
	my_put_nbr.c\
	my_putstr.c\
	my_strcpy.c\
	my_strcmp.c\
	strdup.c\
	my_strlen.c\
	int_to_str.c\
	compare.c\
	my_strcat.c\
	my_strncat.c\
	read_fill.c\
	my_get_nbr.c\
	my_printf/my_function.c\
	my_printf/function.c\
	my_printf/my_put_all.c\
	my_printf/my_put_float.c\
	my_printf/my_put_scientific.c\
	my_printf/float_scient.c\
	my_printf/my_put_scientific_maj.c\
	my_printf/new_p.c\
	my_printf/my_put_nbr2.c\
	my_printf/format.c\
	my_printf/my_put_nbr3.c\
	my_printf/my_printf.c\
	my_printf/my_put_all_p.c\
	my_printf/my_put_nbr4.c\
	str_to_float.c\
	to_arr.c\
	is_alphanum.c\

NAME = libmy.a

OBJ = $(SRC:.c=.o)

$(NAME):
	$(CC) -c $(SRC)
	ar rc $(NAME) *.o
	mkdir -p ../../include
	cp -r $(NAME) ../libmy.a

all: $(NAME)

clean:
	$(RM) *.o
	$(RM) libmy.a ../libmy.a
	clear

fclean: clean

re: fclean all

.PHONY: clean fclean re
