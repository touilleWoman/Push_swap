.PHONY: all clean fclean re

CC ?= gcc

CFLAGS ?= -Wall -Werror -Wextra

NAME = checker

SRCS_NAME = main_checker.c

SRCS_PATH = ./srcs

HEAD_PATH = ./includes

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

HEADER = $(HEAD_PATH)/push_swap.h

OBJ = $(SRCS:.c=.o)

LIBFTA = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(CFLAGS) $(OBJ) $(LIBFTA)

%.o: %.c $(HEADER) $(LIBFTA)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEAD_PATH)

$(LIBFTA): FORCE
	make -C ./libft

FORCE:

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all