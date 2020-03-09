##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compiling mmmmh ? Good idea
##

MAIN				=	src/main.c

SRC					=	src/tetris.c									\
						src/tetriminos_handling/read_tetriminos_dir.c	\
						src/tetriminos_handling/get_tetriminos.c		\

OBJ					=	$(MAIN:.c=.o) $(SRC:.c=.o)

NAME 				=	tetris

override CFLAGS		+=	-W -Wall -Wextra

override CPPFLAGS	+=	-I./include/

override LDFLAGS	+=	-L./lib/

override LDLIBS		+= 	-lmy

LIB 				=	lib/libmy.a

all:					$(NAME)

$(NAME):				$(LIB) $(OBJ)
						$(LINK.o) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIB):
						$(MAKE) -C ./lib/my

debug:					CPPFLAGS += -g
debug:					clean $(LIB) $(OBJ)
						$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:				LDLIBS += -lcriterion --coverage
tests_run:				CFLAGS += --coverage
tests_run:				$(LIB)
						$(CC) -o $@ $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
						./$@
						mv *.gc* tests/
						$(RM) $@

clean:
						$(RM) $(OBJ)
						$(MAKE) -C lib/my clean

fclean:					clean
						$(RM) $(NAME)
						$(RM) $(OBJ)
						$(MAKE) -C lib/my fclean

re:			 			fclean all

.NOTPARALLEL:
.PHONY:					debug all clean fclean re tests_run
