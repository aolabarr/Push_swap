/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:13:59 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/07 17:35:56 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_stackb(t_list **stk_a, t_list **stk_b)
{
	t_cost	cur_cost;

	while (*stk_b != NULL)
	{
		set_cost(*stk_a, *stk_b);
		cur_cost = min_cost(*stk_b);
		//printf("cost total: %d (%d, %d, %d, %d)\n", cur_cost.total, cur_cost.ra,cur_cost.rb,cur_cost.rra,cur_cost.rrb); getchar();
		exe_movements(stk_a, stk_b, cur_cost);
	}
	return ;
}

void	set_cost(t_list *stk_a, t_list *nb)
{
	int		i;
	int		j;
	int		size[2];

	set_cost_zero(nb);
	size[0] = ftps_lstsize(stk_a);
	size[1] = ftps_lstsize(nb);
	i = 0;
	while (nb != NULL)
	{
		if (i <= size[1] / 2 && size[1] != 1)
			nb->cost.rb = i;
		else if (size[1] != 1)
			nb->cost.rrb = size[1] - i;
		j = set_cost_stk_a(stk_a, nb);
		if (j <= size[0] / 2)
			nb->cost.ra = j;
		else
			nb->cost.rra = size[0] - j;
		nb->cost.total = calculate_cost_total(nb->cost);
		//nb->cost.total += nb->cost.ra + nb->cost.rb;
		//nb->cost.total += nb->cost.rra + nb->cost.rrb;
		//printf("cost total: %d\n", nb->cost.total); getchar();
		nb = nb->next;
		i++;
	}
}

t_cost	min_cost(t_list *node)
{
	int		min;
	t_cost	cur_cost;

	min = MAXINT;
	while (node != NULL)
	{
		if (node->idx < min)
		{
			min = node -> idx;
			cur_cost = node -> cost;
		}	
		node = node->next;
	}
	return (cur_cost);
}

int	set_cost_stk_a(t_list *stk_a, t_list *node_b)
{
	int		j;
	t_list	*node_a;
	t_list	*last_a;

	node_a = stk_a;
	last_a = ftps_lstlast(stk_a);
	j = 0;
	if (max_idx(stk_a) < node_b->idx || min_idx(stk_a) > node_b->idx)
	{
		while (node_a->idx != min_idx(stk_a))
		{
			j++;
			node_a = node_a->next;
		}
		return (j);
	}
	else if (last_a->idx < node_b->idx && node_a->idx > node_b->idx)
		return (j);
	while (!(node_a->idx < node_b->idx && node_a->next->idx > node_b->idx))
	{
		j++;
		node_a = node_a->next;
	}
	j++;
	return (j);
}
int	calculate_cost_total(t_cost cost)
{
	int total;
	
	if (cost.ra && cost.rb)
		total = max(cost.ra, cost.rb);
	else if (cost.rra && cost.rrb)
		total = max(cost.rra, cost.rrb);
	else
		total = cost.ra + cost.rb + cost.rra + cost.rrb;
	return (total);
}
