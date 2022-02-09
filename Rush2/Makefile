##
## EPITECH PROJECT, 2022
## B-PDG-300-PAR-3-1-PDGD05-martin.leblancs
## File description:
## Makefile
##

TEST_SRC=	tests/*.c

OBJ=	*.o

NAME=	unit_tests

SRC= *.c

all:	tests_run clean

tests_run:
		gcc -c $(SRC) --coverage
		gcc -c $(TEST_SRC)
		gcc -o $(NAME) *.o -lcriterion -lgcov
		./unit_tests
		gcovr
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean build