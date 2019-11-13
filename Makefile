# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleblond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 18:24:07 by jleblond          #+#    #+#              #
#    Updated: 2019/11/12 18:24:10 by jleblond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC ?= gcc

CFLAGS ?= -Wall -Werror -Wextra

NAME_CK = checker

NAME_PS = push_swap

SRCS_NAME = main_checker.c parse_instructions.c execute_instructions.c instructions.c \
			instructions2.c instructions3.c parse_args.c list_related.c display_functions.c \

SRCS_PATH = ./srcs


SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJ = $(SRCS:.c=.o)

HEAD_PATH = $(shell find . -name includes -type d)

IFLAG = $(foreach dir, $(HEAD_PATH), -I$(dir))

HEADER = $(shell find includes -type f) $(shell find libft/includes -type f)

LIBFTA = ./libft/libft.a

DEBUG =  -g -fsanitize=address

all: $(NAME_CK)

$(NAME_CK): $(OBJ)
	$(CC)  $(CFLAGS) -o $(NAME_CK) $(OBJ) $(LIBFTA) $(DEBUG)

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
