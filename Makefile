##
## EPITECH PROJECT, 2023
## radar_mod
## File description:
## Makefile
##

SRC =	src/main.c\
		src/find_exe.c\
		src/cd.c\
		src/choose_cmd.c\
		src/env.c\
		src/setenv.c\
		src/unsetenv.c\
		src/exit.c\

OBJ = $(SRC:.c=.o)

NAME =	libmy.a

SNAME =	mysh

LDFLAGS = -I./include -L lib/my/ -lmy

# CFLAGS = -Wall -Werror -Wextra

all:	$(NAME) $(SNAME)

$(NAME):
	$(MAKE) -C lib/my/

$(SNAME): $(OBJ)
	gcc -g3 -o $(SNAME) $(SRC) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib/my/
	$(RM) lib/libmy.a lib/my/libmy.a
	clear

coding:
	coding-style . . && cat coding-style-reports.log

re: fclean all

tests_run:
	$(MAKE) tests_run -C try


.PHONY:	all clean fclean re unit_test tests_run
