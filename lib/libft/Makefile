# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:08:51 by aolabarr          #+#    #+#              #
#    Updated: 2024/06/08 16:55:23 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
OBJ_CREATE = -c
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_memset.c ft_memchr.c\
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_strnstr.c ft_memcmp.c ft_tolower.c ft_toupper.c \
		ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_strjoin_freed.c\

OBJS = $(SRC:.c=.o)
NAME = libft.a

$(NAME): $(OBJS)
	ar -cr $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c
	$(CC) $(OBJ_CREATE) $(CFLAGS) $< -o $@

fclean: clean
	rm -f $(NAME) *.out

clean:
	rm -f *.o

re: fclean all 

.PHONY: all fclean clean re


#.SILENT:
