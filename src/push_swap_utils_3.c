/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:06:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/02 18:03:52 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_list **stk)
{
	int		i;
	t_list	*node;

	node = *stk;
	i = 0;
	while (node->idx != 1)
	{
		i++;
		node = node -> next;
	}
	if (i <= ftps_lstsize(*stk) / 2)
	{
		while ((*stk)->idx != 1)
			rev_rotate(stk, 'a');
	}
	else
	{
		while ((*stk)->idx != 1)
			rotate(stk, 'a');
	}
	return ;
}

int	max_idx(t_list *stk)
{
	int	max;

	max = 1;
	while (stk != NULL)
	{
		if (stk->idx > max)
			max = stk->idx;
		stk = stk->next;
	}
	return(max);
}

int	min_idx(t_list *stk)
{
	int	min;

	min = max_idx(stk);
	while (stk != NULL)
	{
		if (stk->idx < min)
			min = stk->idx;
		stk = stk->next;
	}
	return (min);
}

void	set_cost_zero(t_list *stk)
{
	while (stk != NULL)
	{
		stk->cost.ra = 0;
		stk->cost.rra = 0;
		stk->cost.rb = 0;
		stk->cost.rrb = 0;
		stk = stk->next;
	}
}

