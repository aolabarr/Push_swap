/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_orders_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:08:25 by aolabarr          #+#    #+#             */
/*   Updated: 2024/05/17 14:09:16 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_double(t_list **stk_a, t_list **stk_b, int id)
{
    rotate(stk_a, id);
    rotate(stk_b, id);
	if (id == NO_WRITE)
    	ft_putstr_fd("rr\n", STDOUT);
}

void	rev_rotate_double(t_list **stk_a, t_list **stk_b, int id)
{
	rev_rotate(stk_a, id);
    rev_rotate(stk_b, id);
	if (id == NO_WRITE)
    	ft_putstr_fd("rrr\n", STDOUT);
}