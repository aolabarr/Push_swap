/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_orders_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:08:25 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/09 16:19:34 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

void	rotate_double_bn(t_list **stk_a, t_list **stk_b)
{
	rotate_bn(stk_a);
	rotate_bn(stk_b);
}

void	rev_rotate_double_bn(t_list **stk_a, t_list **stk_b)
{
	rev_rotate_bn(stk_a);
	rev_rotate_bn(stk_b);
}

void	swap_double_bn(t_list **stk_a, t_list **stk_b)
{
	swap_bn(stk_a);
	swap_bn(stk_b);
}
