##
## EPITECH PROJECT, 2023
## makefile
## File description:
## qwerfh
##
SRC =	my_function.c	\
	function.c	\
	my_put_all.c	\
	my_put_float.c	\
	my_put_scientific.c	\
	float_scient.c	\
	my_put_scientific_maj.c	\
	new_p.c	\
	my_put_nbr2.c	\
	format.c	\
	my_put_nbr3.c	\
	my_printf.c	\
	my_put_all_p.c	\
	my_put_nbr4.c

CFLAGS = -g

SRC2 =	../../bonus/mini_printf_tests.c

NAME = libmy.a

SNAME =	unit_tests

OBJ = $(SRC:.c=.o)

LDFLAGS = -L . -lmy

TESTFLAGS = --coverage -lcriterion

WFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) -c $(SRC) $(WFLAGS) $(CFLAGS)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../../include
	cp -r my.h ../../include
	cp -r $(NAME) ../../libmy.a

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../../libmy.a
	$(RM) ../../include/my.h

re:	fclean all

unit_test:	fclean $(NAME)
	$(CC) -o $(SNAME) $(SRC) $(SRC2) $(TESTFLAGS) $(WFLAGS)

tests_run:	unit_test
	./unit_tests
	gcovr -r ../.. --exclude ../../bonus/
	$(RM) $(SNAME)
	$(RM) *.gcno *.gcda

.PHONY: all clean fclean re unit_test tests_run
