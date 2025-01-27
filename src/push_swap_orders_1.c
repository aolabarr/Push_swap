/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_orders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:13:40 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/02 12:13:40 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stk, char id)
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
	if (id == 'a')
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	else if (id == 'b')
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	return ;
}

void	rotate(t_list **stk, char id)
{
	t_list	*tmp;
	t_list	*last;

	tmp = (*stk)->next;
	last = ftps_lstlast(*stk);
	last->next = *stk;
	(*stk)->next = NULL;
	*stk = tmp;
	if (id == 'a')
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	else if (id == 'b')
		ft_putstr_fd("rb\n", STDOUT_FILENO);
	return ;
}

void	rev_rotate(t_list **stk, char id)
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
	if (id == 'a')
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	else if (id == 'b')
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	return ;
}

void	push_a(t_list **stk_a,	t_list **stk_b)
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
	ft_putstr_fd("pa\n", STDOUT_FILENO);
	return ;
}

void	push_b(t_list **stk_a, t_list **stk_b)
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
	ft_putstr_fd("pb\n", STDOUT_FILENO);
	return ;
}
