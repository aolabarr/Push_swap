# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 13:37:39 by aolabarr          #+#    #+#              #
#    Updated: 2024/04/13 16:33:38 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libio.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = -rc

SRC =	ft_printf.c \
		ft_printf_utils.c ft_printf_utils_2.c \
		ft_printf_utils_3.c ft_printf_utils_4.c \
		get_next_line.c get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) *.out

re: fclean all

.PHONY: all clean fclean re
