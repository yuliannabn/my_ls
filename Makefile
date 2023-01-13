##
## EPITECH PROJECT, 2022
## MAKEFILE CAT
## File description:
## CAT
##

SRC =	$(wildcard *.c)

NAME = my_ls

FLAGS = -W -Wall -Wpedantic -Wno-long-long -g -Werror

FLAGSXTA = -I include/

all = $(NAME)

$(NAME):
	cd lib; make
	gcc -o $(NAME) $(FLAGS) src/*.c $(FLAGSXTA) -L lib/ -lmy

clean:
	cd lib; make clean
	rm -f *#
	rm -f *~

fclean: clean
	rm -f $(NAME)
	cd lib; make fclean

re: fclean $(NAME)
