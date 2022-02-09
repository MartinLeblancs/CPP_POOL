##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	*.c

OBJ	=	*.o

NAME=	z

CFLAGS=  -std=gnu17 -Wall -Wextra

all:	build

build:
		gcc $(CFLAGS) $(SRC) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
