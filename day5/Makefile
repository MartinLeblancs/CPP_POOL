##
## EPITECH PROJECT, 2022
## B-PDG-300-PAR-3-1-PDGD05-martin.leblancs
## File description:
## Makefile
##

SRC	=	*.c

OBJ	=	*.o

NAME= libstring.a

CFLAGS=  -std=gnu17 -Wall -Wextra

all:	build clean

build:
		gcc -c $(SRC)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: clean build