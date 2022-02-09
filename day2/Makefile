##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC = ghci

SRC	=	DoOp.hs 

OBJ	=	*.hi *.o

NAME=	doop

all:	build

build: 
		$(CC) $(SRC) -o $(NAME)

re: clean build

clean: 
		rm -f $(NAME)

fclean: clean
		rm -f $(NAME)
		rm -f $(OBJ) 