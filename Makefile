# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:08:51 by aolabarr          #+#    #+#              #
#    Updated: 2024/04/27 14:19:19 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
OBJ_CREATE = -c
CFLAGS = -Wall -Wextra -Werror

INC_DIR = ./src
LIBFT_DIR = ./src/libft
LIBLST_DIR = ./src/liblst

SRC =	push_swap.c \

OBJS = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -L$(LIBLST_DIR) -lft -llst $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(OBJ_CREATE) $(CFLAGS) -I$(INC_DIR) $< -o $@

lib:
	make -C $(LIBFT_DIR)
	make -C $(LIBLST_DIR)

fclean: clean
	rm -f $(NAME) *.out
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBLST_DIR)

clean:
	rm -f *.o
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBLST_DIR)

re: fclean all 

.PHONY: all fclean clean re lib


#.SILENT:
