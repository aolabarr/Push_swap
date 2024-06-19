/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_orders_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:37:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/08 17:37:20 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

void	swap_bn(t_list **stk)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (ftps_lstsize(*stk) == 1)
		return ;
	tmp1 = (*stk)->next;
	tmp2 = (*stk)->next->next;
	(*stk)->next->next = (*stk);
	(*stk)->next = tmp2;
	*stk = tmp1;
	return ;
}

void	rotate_bn(t_list **stk)
{
	t_list	*tmp;
	t_list	*last;

	printf("Prueba E\n");
	tmp = (*stk)->next;
	last = ftps_lstlast(*stk);
	last->next = *stk;
	(*stk)->next = NULL;
	*stk = tmp;
	return ;
}

void	rev_rotate_bn(t_list **stk)
{
	t_list	*tmp;
	t_list	*slast;
	t_list	*last;
	int		i;

	last = ftps_lstlast(*stk);
	slast = *stk;
	i = 0;
	while (i < ftps_lstsize(*stk) - 2)
	{
		slast = slast -> next;
		i++;
	}
	tmp = slast->next;
	last -> next = *stk;
	slast -> next = NULL;
	*stk = tmp;
	return ;
}

void	push_a_bn(t_list **stk_a, t_list **stk_b)
{
	t_list	*tmp;

	if (ftps_lstsize(*stk_b) != 1)
	{
		tmp = (*stk_b)->next;
		(*stk_b)->next = *stk_a;
		*stk_a = *stk_b;
		*stk_b = tmp;
	}
	else
	{
		(*stk_b)->next = *stk_a;
		*stk_a = *stk_b;
		*stk_b = NULL;
	}
	return ;
}

void	push_b_bn(t_list **stk_a, t_list **stk_b)
{
	t_list	*tmp;

	if (*stk_b == NULL)
	{
		*stk_b = *stk_a;
		*stk_a = (*stk_a)->next;
		(*stk_b)->next = NULL;
	}
	else
	{
		tmp = (*stk_a)-> next;
		(*stk_a)-> next = *stk_b;
		*stk_b = *stk_a;
		*stk_a = tmp;
	}
	return ;
}
