/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:39:09 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/10 10:19:32 by aolabarr         ###   ########.fr       */
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
# define NO_WRITE 0

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h> 
# include "../lib/libft/libft.h"
# include "../lib/liblst/liblst.h"

// PARSE
t_list	*manage_input_data(int ac, char **av);
t_list	*create_stack(char **ptr);
char	**copy_arguments(int ac, char **av);
void	put_sorted_index(t_list *stack);

// ERRORS
void	check_errors(char **ptr);
int		ft_str_is_numeric(char *str);
int		ft_is_int(char *str);
int		ft_str_norepeat_in_mat(char **ptr);

//UTILS 1
void	manage_push_swap(t_list **stack);
void	push_swap(t_list **stack_a);
void	fill_stackb(t_list **stk_a, t_list **stk_b);
void	final_sort(t_list **stk);

//UTILS 2
void	empty_stackb(t_list **stk_a, t_list **stk_b);
void	set_cost(t_list *stk_a, t_list *stk_b);
t_cost	min_cost(t_list *stk);
int		set_cost_stk_a(t_list *stk_a, t_list *node_b);
int     calculate_cost_total(t_cost cost);

//EXE
void	exe_movements(t_list **stk_a, t_list **stk_b, t_cost cur_cost);
t_cost	exe_double_rot(t_list **stk_a, t_list **stk_b, t_cost cur_cost);
t_cost	exe_double_rev_rot(t_list **stk_a, t_list **stk_b, t_cost cur_cost);

//UTILS 3
void	sort_2stack(t_list **stk_a);
void	sort_3stack(t_list **stk_a);
void	sort_5stack(t_list **stk_a);

//UTILS 4
void	set_cost_zero(t_list *stk);
int		max_idx(t_list *stk);
int		min_idx(t_list *stk);
int		abs(int a);
int		max(int a, int b);

//FREE
void	ft_free_mat(char **mat, size_t size);
void	ft_free_array(int **array);

//LISTS
size_t	ft_matsize(char **str);
void	ft_lst_putnbr_fd(t_list *lst, int fd);
int		ft_lst_is_sorted(t_list *lst);

// ARRAYS
int		*create_array(t_list *stack);
void	ft_bubble_sort(int *array, int size);
int		ft_array_is_sorted(int *array, int size);
void	ft_swap_nbr(int *a, int *b);

//ORDERS 1
void	swap(t_list **stack, char id);
void	rotate(t_list **stk, char id);
void	rev_rotate(t_list **stack, char id);
void	push_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);

//ORDERS 2
void	rotate_double(t_list **stk_a, t_list **stk_b, int id);
void	rev_rotate_double(t_list **stk_a, t_list **stk_b, int id);

#endif
