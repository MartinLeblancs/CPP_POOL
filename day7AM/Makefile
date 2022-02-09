##
## EPITECH PROJECT, 2022
## ex01
## File description:
## Makefile
##

CC=		g++

SRC	=	*.cpp

OBJ	=	*.o

NAME= 	my_convert_temp

CFLAGS=  std=c++20 -Wall -Wextra -Werror

all:	build clean

build:
		$(CC) $(SRC) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: clean build