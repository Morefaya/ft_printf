CC = gcc
CFLAG = -Wall -Wextra -Werror
SRC = main.c parse_width.c parse_attr.c print_nbr.c print_str.c parse_pres.c \
size_base.c putlong_char.c putlong_nbr.c putlun_nbr.c putshort_nbr.c putchar_nbr.c \
print_space_left.c parse_modifier.c atoi_base.c putint_base.c tool.c szb.c
SRC_DIR = ./src
SRC_C = $(patsubst %, $(SRC_DIR)/%, $(SRC))
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_DIR = ./obj
OBJ_O = $(patsubst %, $(OBJ_DIR)/%, $(OBJ))
HDIR = include
LDIR = libft
LIB = ft
FILE =
NAME = ft_printf
.PHONY: re run rr clean fclean all

all: $(LDIR)/lib$(LIB).a $(NAME)

$(LDIR)/lib$(LIB).a:
	@make -C $(LDIR)

fclean_lib:
	@make fclean -C $(LDIR)

$(NAME): $(OBJ_DIR) $(OBJ_O)
	@$(CC) -o $@ -I $(HDIR) -l $(LIB) -L $(LDIR) $(OBJ_O) $(CFLAG)
	@echo "\033[32m$(NAME) done\033[0m"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@ -I $(HDIR) $(CFLAG)

clean:
	@rm -rf $(OBJ_O)
	@echo "\033[31mobject files removed\033[0m"

fclean: clean fclean_lib
	@rm -rf $(NAME)
	@echo "\033[31m$(NAME) removed\033[0m"

re: fclean all

run:
	@./$(NAME) $(FILE) | cat -e

rr: re run
