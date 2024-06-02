# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:08:51 by aolabarr          #+#    #+#              #
#    Updated: 2024/06/02 14:12:51 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
NO_LINK = -c
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = ./obj
SRC_DIR = ./src
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
		push_swap_utils_2.c\
		push_swap_utils_3.c\

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: lib $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(LIBLST_DIR) -lft -llst -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

lib:
	make -C $(LIBFT_DIR)
	make -C $(LIBLST_DIR)

fclean: clean
	rm -R $(OBJ_DIR)
	rm -f $(NAME) *.out
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBLST_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBLST_DIR)

re: fclean all 

.PHONY: all fclean clean re lib


#.SILENT:
