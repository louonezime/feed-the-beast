##
## EPITECH PROJECT, 2024
## feed-the-beast
## File description:
## Makefile
##

CPPFLAGS += -I../../include

SRC	=	my_str_to_word_array.c 	\
		my_arraylen.c			\
		my_free_array.c 		\
		my_strcat.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re:	fclean all

.PHONY = all clean fclean re
