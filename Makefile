# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:08:51 by aolabarr          #+#    #+#              #
#    Updated: 2024/05/03 10:31:46 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
NO_LINK = -c
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src
INC_DIR = ./lib
LIBFT_DIR = ./lib/libft
LIBLST_DIR = ./lib/liblst

SRC =	$(SRC_DIR)/push_swap_main.c \
		$(SRC_DIR)/push_swap_errors.c\
		$(SRC_DIR)/push_swap_arrays.c\
		$(SRC_DIR)/push_swap_lists.c\
		$(SRC_DIR)/push_swap_orders.c\
		$(SRC_DIR)/push_swap_free.c\
		$(SRC_DIR)/push_swap_utils.c\

OBJS = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(LIBLST_DIR) -lft -llst -o $(NAME)

%.o: %.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

lib:
	make -C $(LIBFT_DIR)
	make -C $(LIBLST_DIR)

fclean: clean
	rm -f $(NAME) *.out
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBLST_DIR)

clean:
	rm -f $(SRC_DIR)/*.o
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBLST_DIR)

re: fclean all 

.PHONY: all fclean clean re lib


#.SILENT:
