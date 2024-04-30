/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:39:09 by aolabarr          #+#    #+#             */
/*   Updated: 2024/05/01 01:11:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAXINT 2147483647
# define MININT -2147483648
# define MAXINT_STR "2147483647"
# define MININT_STR "-2147483648"
# define STDOUT 1
# define STDERR 2
# define ERROR_MESSAGE "Error\n"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h> 
# include "lib/libft/libft.h"
# include "lib/liblst/liblst.h"

t_list	*create_stack(char *str);
int     *create_array(t_list *stack);
void	put_sorted_index(t_list *stack);
int     check_errors(char *str);
void	ft_free_mat(char **mat, size_t size);
void	ft_free_array(int **array);

size_t	ft_matsize(char **str);
int     ft_str_is_numeric(char *str);
void    ft_lst_putnbr_fd(t_list *lst, int fd);
int     ft_lst_is_sorted(t_list *lst);
void	ft_bubble_sort(int *array, int size);
int     ft_array_is_sorted(int *array, int size);
void	ft_swap_nbr(int *a, int *b);


#endif
