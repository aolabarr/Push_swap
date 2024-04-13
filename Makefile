# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:08:51 by aolabarr          #+#    #+#              #
#    Updated: 2024/04/13 19:23:45 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
OBJ_CREATE = -c
CFLAGS = -Wall -Wextra -Werror
INC_DIR = ./lib
LIB_DIR = ./lib

SRC =	main.c \

OBJS = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -lft $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(OBJ_CREATE) $(CFLAGS) -I$(INC_DIR) $< -o $@

lib:
	make -C ./lib

fclean: clean
	rm -f $(NAME) *.out
	make fclean -C ./lib

clean:
	rm -f *.o
	make clean -C ./lib

re: fclean all 

.PHONY: all fclean clean re lib


#.SILENT:
