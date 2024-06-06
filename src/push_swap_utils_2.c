/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:13:59 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/06 15:27:22 by aolabarr         ###   ########.fr       */
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
		exe_movements(stk_a, stk_b, cur_cost);
		/*
		//PRINT NODES & IDX
		t_list	*node_a;
		t_list	*node_b;
    	printf("\nStk_A\tidx\n");
		node_a = *stk_a;
		while (node_a != NULL)
		{
			printf("%d\t%d\n", node_a->content, node_a->idx);
			node_a = node_a -> next;
		}
    	node_b = *stk_b;
    	while (node_b != NULL)
		{
			printf("%d\t%d\n", node_b->content, node_b->idx);
			node_b = node_b -> next;
		}
		*/
	}
	return ;
}

void	set_cost(t_list *stk_a, t_list *node_b)
{
	int		i;
	int		j;
	int		size[2];
	
	set_cost_zero(node_b);
	size[0] = ftps_lstsize(stk_a);
	size[1] = ftps_lstsize(node_b);
	i = 0;
	while(node_b != NULL)
	{
		if (i <= size[1] / 2 && size[1] != 1)
			node_b->cost.rb = i;
		else if (size[1] != 1)
			node_b->cost.rrb = size[1] - i;
		j = set_cost_stk_a(stk_a, node_b);
		if (j <= size[0] / 2)
			node_b->cost.ra = j;
		else
			node_b->cost.rra = size[0] - j;
		node_b->cost.total = node_b->cost.ra + node_b->cost.rb + node_b->cost.rra +node_b-> cost.rrb;
		node_b = node_b->next;
		i++;
	}
}

t_cost	min_cost(t_list *stk)
{
	int		min;
	t_list	*node;

	min = MAXINT;
	node = stk;
	while (node != NULL)
	{
		if (node->content < min)
			min = node -> content;
		node = node->next;
	}
	node = stk;
	while(node ->content != min)
		node = node -> next;
	return (node->cost);
}

int	set_cost_stk_a(t_list *stk_a, t_list *node_b)
{
	int	j;
	t_list *node_a;
	
	node_a = stk_a;
	j = 0;
	if (max_idx(stk_a) < node_b->idx || min_idx(stk_a) > node_b->idx)
	{
		while(node_a->idx != min_idx(stk_a))
		{
			j++;
			node_a = node_a->next;
		}
	}
	else
	{
		while(node_a->idx < node_b->idx && !(node_a->next->idx > node_b->idx))
		{
			j++;
			node_a = node_a->next;
		}
		j++;
	}
	return (j);
}

void	exe_movements(t_list **stk_a, t_list **stk_b, t_cost cur_cost)
{
	int	i;
	int	rpt;

	i = 0;
	if (cur_cost.ra && cur_cost.rb)
	{
		//exe_double_moves_rot(stk_a, stk_b, &cur_cost);
		
		rpt = max(cur_cost.ra, cur_cost.rb) - abs(cur_cost.ra - cur_cost.rb);
		while (i++ < rpt)
			rotate_double(stk_a, stk_b, NO_WRITE);
		if (cur_cost.ra > cur_cost.rb)
		{
			cur_cost.ra = cur_cost.ra - cur_cost.rb;
			cur_cost.rb = 0;
		}
		else
		{
			cur_cost.rb = cur_cost.rb - cur_cost.ra;
			cur_cost.ra = 0;
		}
		
	}
	i = 0;
	if (cur_cost.rra && cur_cost.rrb)
	{
		rpt = max(cur_cost.rra, cur_cost.rrb) - abs(cur_cost.rra - cur_cost.rrb);
		while (i++ < rpt)
			rev_rotate_double(stk_a, stk_b, NO_WRITE);
		if (cur_cost.rra > cur_cost.rrb)
		{
			cur_cost.rra = cur_cost.rra - cur_cost.rrb;
			cur_cost.rrb = 0;
		}
		else
		{
			cur_cost.rrb = cur_cost.rrb - cur_cost.rra;
			cur_cost.rra = 0;
		}
	}
	
	i = 0;
	if (cur_cost.ra)
		while (i++ < cur_cost.ra)
			rotate(stk_a, 'a');
	else
		while (i++ < cur_cost.rra)
			rev_rotate(stk_a, 'a');
	i = 0;
	if (cur_cost.rb)
		while (i++ < cur_cost.rb)
			rotate(stk_b, 'b');
	else
		while (i++ < cur_cost.rrb)
			rev_rotate(stk_b, 'b');
	push_a(stk_a, stk_b);
}

void	exe_double_moves_rot(t_list **stk_a, t_list **stk_b, t_cost *cur_cost)
{
	int	rpt;
	int	i;

	rpt = max((*cur_cost).ra, (*cur_cost).rb) - abs((*cur_cost).ra - (*cur_cost).rb);
	while (i++ < rpt)
		rotate_double(stk_a, stk_b, NO_WRITE);
	if ((*cur_cost).ra > (*cur_cost).rb)
	{
		(*cur_cost).ra = (*cur_cost).ra - (*cur_cost).rb;
		(*cur_cost).rb = 0;
	}
	else
	{
		(*cur_cost).rb = (*cur_cost).rb - (*cur_cost).ra;
		(*cur_cost).ra = 0;
	}

}