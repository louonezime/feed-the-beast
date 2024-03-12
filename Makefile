##
## EPITECH PROJECT, 2024
## feed-the-beast
## File description:
## Makefile
##

CXXFLAGS += -Wall -Wextra -Werror
CPPFLAGS = -iquote./include

CC	=	gcc

NAME	=	strace

BASE_SRC	=	src/main.c	\
				$(SRC)

SRC	=	src/strace.c	\
		src/parsing.c	\
		src/my.c
OBJ	=	$(BASE_SRC:.c=.o)

TEST_NAME	=	unit_tests

TEST_SRC	=	tests/

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

$(TEST_NAME): $(SRC) $(TEST_SRC)
	$(CC) $(SRC) $(TEST_SRC) $(CPPFLAGS) --coverage -lcriterion -o $(TEST_NAME)

tests_run:	$(TEST_NAME)
	./$(TEST_NAME)

debug: CXXFLAGS += -g3 -D DEBUG
debug: re

.PHONY:	all clean fclean re debug tests_run
