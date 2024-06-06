/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:13:59 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/06 18:06:03 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_stackb(t_list **stk_a, t_list **stk_b)
{
	t_cost	cur_cost;

	while (*stk_b != NULL)
	{
		set_cost(*stk_a, *stk_b);
		//printf("Prueba\t");
		cur_cost = min_cost(*stk_b);
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
		nb->cost.total = nb->cost.ra + nb->cost.rb;
		nb->cost.total += nb->cost.rra + nb->cost.rrb;
		nb = nb->next;
		i++;
	}
}

t_cost	min_cost(t_list *stk)
{
	int		min;
	t_list	*node;
	t_cost	cur_cost;

	min = MAXINT;
	node = stk;
	while (node != NULL)
	{
		if (node->content < min)
		{
			min = node -> content;
			cur_cost = node -> cost;
		}	
		node = node->next;
	}
	//node = stk;
	//while (node->idx != min)
	//	node = node -> next;
	//printf("moved idx: %d\tcost: %d\n", node->idx, node->cost.total);
	return (cur_cost);
}

int	set_cost_stk_a(t_list *stk_a, t_list *node_b)
{
	int		j;
	t_list	*node_a;

	node_a = stk_a;
	j = 0;
	if (max_idx(stk_a) < node_b->idx || min_idx(stk_a) > node_b->idx)
	{
		while (node_a->idx != min_idx(stk_a))
		{
			j++;
			node_a = node_a->next;
		}
	}
	else
	{
		while (node_a->idx < node_b->idx && !(node_a->next->idx > node_b->idx))
		{
			j++;
			node_a = node_a->next;
		}
		j++;
	}
	return (j);
}
