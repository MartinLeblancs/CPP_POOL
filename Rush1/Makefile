CC	=	ghc

SRC	= Main.hs\
	Function.hs\
	ErrorHandling.hs\

NAME	=	pushswap_checker

TEST_SRC	=	Function.hs \
				Error_handling.hs \
				Tests/tests.hs

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC)

tests_run:  $(TEST_SRC)
			$(CC) $(TEST_SRC) -o $(TEST)
			./$(TEST)

clean:
	rm -f *.hi
	rm -f *.o
	rm -f tests/*.o
	rm -f tests/*.hi
	rm -f $(TEST)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re