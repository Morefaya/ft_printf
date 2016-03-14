CC = gcc
SRC = ft_putint_base.c check_base.c ft_putchar.c ft_putint.c ft_pow.c ft_strlen.c main_putint_base.c
OBJ = $(patsubst %.c, %.o, $(SRC))
CFLAG = -Wall -Wextra -Werror
NAME = putint_base
.PHONY: %.o re

all: objet exe

objet:
	$(CC) -c $(SRC) $(CFLAG)
exe:
	$(CC) -o $(NAME) $(OBJ) $(CFLAG)
%.o: %.c
	$(CC) -c $< $(CFLAG)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
