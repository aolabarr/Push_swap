# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:08:51 by aolabarr          #+#    #+#              #
#    Updated: 2024/06/09 20:06:52 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
NO_LINK = -c
CFLAGS = -Wall -Wextra -Werror -g3
SFLAGS =  -fsanitize=leak

OBJ_DIR = ./obj
SRC_DIR = ./src
OBJ_DIR_BONUS = ./obj_bonus
SRC_DIR_BONUS = ./src_bonus

INC_DIR = ./lib
LIBFT_DIR = ./lib/libft
LIBLST_DIR = ./lib/liblst

SRC =	push_swap_main.c \
		push_swap_parse.c\
		push_swap_errors.c\
		push_swap_arrays.c\
		push_swap_lists.c\
		push_swap_exe.c\
		push_swap_orders_1.c\
		push_swap_orders_2.c\
		push_swap_free.c\
		push_swap_utils_1.c\
		push_swap_utils_2.c\
		push_swap_utils_3.c\
		push_swap_utils_4.c\

SRC_BONUS = ps_bonus_main.c\
			ps_bonus_orders_1.c\
			ps_bonus_orders_2.c\

SRC_BONUS_AUX = push_swap_parse.c\
				push_swap_errors.c\
				push_swap_arrays.c\
				push_swap_lists.c\
				push_swap_free.c\

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS)/,$(SRC_BONUS:.c=.o))
OBJS_BONUS_AUX = $(addprefix $(OBJ_DIR_BONUS)/,$(SRC_BONUS_AUX:.c=.o))

all: lib $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(LIBLST_DIR) -lft -llst -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

sanitizer: lib $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(SFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(LIBLST_DIR) -lft -llst -o $(NAME)

bonus: lib $(OBJ_DIR_BONUS) $(NAME_BONUS)
	
$(NAME_BONUS): $(OBJS_BONUS) $(OBJS_BONUS_AUX)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(OBJS_BONUS_AUX) -L$(LIBFT_DIR) -L$(LIBLST_DIR) -lft -llst -o $(NAME_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR_BONUS):
	mkdir $(OBJ_DIR_BONUS)

lib:
	make -C $(LIBFT_DIR)
	make -C $(LIBLST_DIR)

fclean: clean
	rm -f $(NAME) *.out
	rm -f $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBLST_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
	@if [ -d $(OBJ_DIR_BONUS) ]; then rm -rf $(OBJ_DIR_BONUS); fi
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBLST_DIR)

re: fclean all

.PHONY: all fclean clean re lib sanitizer bonus


#.SILENT:
