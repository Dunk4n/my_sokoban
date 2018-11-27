##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##


D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./lib/my/

SRC	=	$(D_SRC)main.c		\
		$(D_SRC)score.c		\
		$(D_SRC)game.c		\
		$(D_SRC)direction.c	\
		$(D_SRC)map.c

OBJ	=	$(SRC:%.c=%.o)

NAME	=	my_sokoban

CFLAGS	=	-W -Wall -Wextra -I$(D_INC)

LDFLAGS	=	-L$(D_LIB) -lmy -lncurses

TEST_LDFLAGS	=	$(LDFLAGS) -lcriterion

TEST_CFLAGS	=	$(CFLAGS) --coverage

TEST_MAIN	=	../tests/test_infin.c

all	:	$(NAME)

libmy	:
		make -C $(D_LIB)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		$(MAKE) -C $(D_LIB) fclean
		rm -f $(NAME)
		rm -f *~

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) $(TEST_LDFLAGS) $(CFLAGS)
	rm -f $(OBJ)

re	:
		$(MAKE) fclean
		$(MAKE) all

.PHONY	:	 all clean fclean re
