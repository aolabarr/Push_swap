/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:21:31 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/19 10:22:59 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BONUS_H
# define PS_BONUS_H

# include "../src/push_swap.h"
# include <stdlib.h>

# define BUFFER_SIZE 1

char	**read_stdin(void);
void	exe_order(t_list **stack_a, t_list **stack_b, char *ord);
void	write_result(t_list *stack_a, t_list *stack_b);
void	handle_orders(t_list **stack_a, t_list **stack_b, char **ords);

// ORDERS 1
void	swap_bn(t_list **stk);
void	rotate_bn(t_list **stk);
void	rev_rotate_bn(t_list **stk);
void	push_a_bn(t_list **stk_a,	t_list **stk_b);
void	push_b_bn(t_list **stk_a, t_list **stk_b);

//ORDERS 2
void	rotate_double_bn(t_list **stk_a, t_list **stk_b);
void	rev_rotate_double_bn(t_list **stk_a, t_list **stk_b);
void	swap_double_bn(t_list **stk_a, t_list **stk_b);

#endif
