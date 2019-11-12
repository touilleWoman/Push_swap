.PHONY: all clean fclean re

CC ?= gcc

CFLAGS ?= -Wall -Werror -Wextra

NAME = checker

SRCS_NAME = main_checker.c execute_instructions.c instructions.c

SRCS_PATH = ./srcs


SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJ = $(SRCS:.c=.o)

HEAD_PATH = $(shell find . -name includes -type d)

IFLAG = $(foreach dir, $(HEAD_PATH), -I$(dir))

HEADER = $(shell find includes -type f) $(shell find libft/includes -type f)

LIBFTA = ./libft/libft.a

DEBUG =  -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFTA) $(DEBUG)

%.o: %.c $(HEADER) $(LIBFTA)
	$(CC) $(CFLAGS) -o $@ -c $< $(IFLAG)

$(LIBFTA): FORCE
	make -C libft

FORCE:

clean:
	make clean -C libft
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)

re: fclean all