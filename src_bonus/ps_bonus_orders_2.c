/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_orders_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:08:25 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/29 10:54:01 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

void	rotate_double_bn(t_list **stk_a, t_list **stk_b)
{
	if (*stk_a == NULL || *stk_a == NULL)
		return ;
	if (ftps_lstsize(*stk_a) <= 1 || ftps_lstsize(*stk_b) <= 1)
		return ;
	rotate_bn(stk_a);
	rotate_bn(stk_b);
	return ;
}

void	rev_rotate_double_bn(t_list **stk_a, t_list **stk_b)
{
	if (*stk_a == NULL || *stk_a == NULL)
		return ;
	if (ftps_lstsize(*stk_a) <= 1 || ftps_lstsize(*stk_b) <= 1)
		return ;
	rev_rotate_bn(stk_a);
	rev_rotate_bn(stk_b);
	return ;
}

void	swap_double_bn(t_list **stk_a, t_list **stk_b)
{
	if (*stk_a == NULL || *stk_a == NULL)
		return ;
	if (ftps_lstsize(*stk_a) <= 1 || ftps_lstsize(*stk_b) <= 1)
		return ;
	swap_bn(stk_a);
	swap_bn(stk_b);
	return ;
}
