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

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME_CK = checker
NAME_PS = push_swap

SRCS_NAME = parse_instructions.c execute_instructions.c instructions.c \
			instructions2.c instructions3.c parse_args.c list_related.c \
			display_functions.c tools.c launch_algo.c\


SRCS_PATH = ./srcs

FILE_CK = main_checker.c
FILE_PS = main_push_swap.c

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
SRC_CK = $(addprefix $(SRCS_PATH)/, $(FILE_CK))
SRC_PS = $(addprefix $(SRCS_PATH)/, $(FILE_PS))

OBJ = $(SRCS:.c=.o)
OBJ_CK = $(SRC_CK:.c=.o)
OBJ_PS = $(SRC_PS:.c=.o)



HEAD_PATH = $(shell find . -name includes -type d)

IFLAG = $(foreach dir, $(HEAD_PATH), -I$(dir))

HEADER = $(shell find includes -type f) $(shell find libft/includes -type f)

LIBFTA = ./libft/libft.a

# DEBUG =  -g -fsanitize=address
DEBUG =  -g

all: $(NAME_CK) $(NAME_PS)

$(NAME_PS):$(OBJ) $(OBJ_PS)
	$(CC)  $(CFLAGS) -o $(NAME_PS) $(SRC_PS) $(OBJ) $(LIBFTA) $(DEBUG) $(IFLAG)

$(NAME_CK): $(OBJ) $(OBJ_CK)
	$(CC)  $(CFLAGS) -o $(NAME_CK) $(SRC_CK) $(OBJ) $(LIBFTA) $(DEBUG) $(IFLAG)

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

	# when modify main, doesn't recompile !!!???
