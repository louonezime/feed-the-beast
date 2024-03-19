##
## EPITECH PROJECT, 2024
## feed-the-beast
## File description:
## Makefile
##

CXXFLAGS += -Wall -Wextra -Werror
CPPFLAGS = -iquote./include

LDFLAGS = -L./lib/my
LDLIBS = -lmy

CC	=	gcc

NAME	=	strace

BASE_SRC	=	src/main.c	\
				$(SRC)

SRC	=	src/strace.c			\
		src/parsing.c			\
		src/util_messages.c		\
		src/error_handling.c	\
		src/pid.c				\
		src/parameters.c
OBJ	=	$(BASE_SRC:.c=.o)

TEST_NAME	=	unit_tests

TEST_SRC	=

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	make clean -C ./lib/my
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C ./lib/my
	$(RM) $(TEST_NAME)
	$(RM) $(NAME)

re:	fclean all

$(TEST_NAME): $(SRC) $(TEST_SRC)
	make -C ./lib/my
	$(CC) $(SRC) $(TEST_SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) \
		--coverage -lcriterion -o $(TEST_NAME)

tests_run:	$(TEST_NAME)
	./$(TEST_NAME)

debug: CXXFLAGS += -g3
debug: re

.PHONY:	all clean fclean re debug tests_run
