# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:08:51 by aolabarr          #+#    #+#              #
#    Updated: 2024/05/01 20:52:20 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
OBJ_CREATE = -c
CFLAGS = -Wall -Wextra -Werror

INC_DIR = ./lib
LIBFT_DIR = ./lib/libft
LIBLST_DIR = ./lib/liblst

SRC =	push_swap_main.c \
		push_swap_errors.c\
		push_swap_arrays.c\
		push_swap_lists.c\
		push_swap_orders.c\
		push_swap_free.c\
		push_swap_utils.c\

OBJS = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(LIBLST_DIR) -lft -llst -o $(NAME)
#$(CC) $(CFLAGS) libft.a $(OBJS) -o $(NAME)

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
