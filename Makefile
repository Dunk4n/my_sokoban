##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./lib/my/
D_SRCT	=	./tests/

SRC	=	$(D_SRC)main.c		\
		$(D_SRC)game.c		\
		$(D_SRC)direction.c	\
		$(D_SRC)size_map.c	\
		$(D_SRC)map_val.c	\
		$(D_SRC)map.c

OBJ	=	$(SRC:%.c=%.o)

NAME	=	my_sokoban

CFLAGS	=	-W -Wall -Wextra -I$(D_INC)

LDFLAGS	=	-L$(D_LIB) -lmy -lncurses

TEST_LDFLAGS =	$(LDFLAGS) -lcriterion

TEST_CFLAGS =	$(CFLAGS) --coverage

TESTS_SRC	=	$(D_SRCT)test_map.c		\
			$(D_SRCT)test_direction.c	\
			$(D_SRCT)test_direction2.c	\
			$(D_SRCT)test_game.c		\
			$(D_SRCT)test_level.c		\
			$(D_SRC)game.c			\
			$(D_SRC)direction.c		\
			$(D_SRC)size_map.c		\
			$(D_SRC)map_val.c		\
			$(D_SRC)map.c

all: $(NAME)

libmy:
	make -C $(D_LIB)

clean:
	rm -f $(OBJ)

clean_tests:
	rm -f *.gcno *.gcda

fclean:
	$(MAKE) clean
	$(MAKE) -C $(D_LIB) fclean
	$(MAKE) clean_tests
	rm -f $(NAME)
	rm -f *~

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

re:
	$(MAKE) fclean
	$(MAKE) all

tests: $(OBJ) clean
	$(MAKE) -C lib/my
	gcc -o unit_test $(TESTS_SRC) $(TEST_LDFLAGS) $(TEST_CFLAGS)

coverage:
	gcovr --exclude tests/

.PHONY: all clean fclean re
