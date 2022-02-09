NAME	=	MyGKrellm

SRC		=	src/main.cpp	\
			src/core.cpp	\
			src/data.cpp	\
			src/graphic.cpp	\
			src/ncurse.cpp \

OBJ		=	$(SRC:.cpp=.o)

CPPFLAGS	=	-I./include/

CFLAGS		=	-Werror -Wextra -Wall

LDFLAGS		=	-lncurses -lsfml-graphics -lsfml-window -lsfml-system

all		:	$(OBJ)
			g++ $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re