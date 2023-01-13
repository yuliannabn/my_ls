##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## ...
##

SRC =	$(wildcard *.c)

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
