/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:39:09 by aolabarr          #+#    #+#             */
/*   Updated: 2024/05/04 17:52:52 by marvin           ###   ########.fr       */
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
# define EXITCODE 1
# define ERROR_MESSAGE "Error\n"
# define PARTS 4


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h> 
# include "../lib/libft/libft.h"
# include "../lib/liblst/liblst.h"

t_list	*create_stack(char *str);
void	put_sorted_index(t_list *stack);

void    check_errors(char *str);
int     ft_str_is_numeric(char *str);
int     ft_is_int(char *str);
int     ft_str_norepeat_in_mat(char **ptr);

void    manage_push_swap(t_list **stack);
void    push_swap(t_list **stack_a);
void    fill_stackb(t_list **stk_a, t_list **stk_b);
void    sort_2stack(t_list **stk_a);
void    sort_3stack(t_list **stk_a);

void	ft_free_mat(char **mat);
void	ft_free_array(int **array);

size_t	ft_matsize(char **str);
void    ft_lst_putnbr_fd(t_list *lst, int fd);
int     ft_lst_is_sorted(t_list *lst);

int     *create_array(t_list *stack);
void	ft_bubble_sort(int *array, int size);
int     ft_array_is_sorted(int *array, int size);
void	ft_swap_nbr(int *a, int *b);

void    swap(t_list **stack, char id);
void    rotate(t_list **stk, char id);
void    rev_rotate(t_list **stack, char id);
void    push_b(t_list **stack_a, t_list **stack_b);
void    push_a(t_list **stack_a, t_list **stack_b);

#endif
