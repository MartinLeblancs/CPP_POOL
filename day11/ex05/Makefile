##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC = g++

SRC	=	Picture.cpp \
		Toy.cpp		\

TEST_SRC = 		Picture.cpp	\
					Toy.cpp			\
					tests/test_toy.cpp	\
					tests/test_buzz.cpp	\
					Woody.cpp			\
					Buzz.cpp		\

OBJ	=	$(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++20

NAME =	a.out

all:	build clean

tests_run:  clean
			$(CC) $(TEST_SRC) -o $(NAME) -lcriterion --coverage
			./$(NAME)

build:
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
		rm -f $(OBJ)
		rm -f test/$(OBJ)
		rm -f $(TEST)
		rm -f ./*.gcno
		rm -f ./*.gcda


fclean: clean
		rm -f $(NAME)

re: fclean build

.PHONY: all clean fclean re