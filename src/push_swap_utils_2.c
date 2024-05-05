
#include "push_swap.h"

void	empty_stackb(t_list **stk_a, t_list **stk_b)
{
	t_cost	cur_cost;
	int		i;
	//t_list	*node_a;
	//t_list	*node_b;

	while (*stk_b != NULL)
	{
		set_cost(*stk_a, *stk_b);
		cur_cost = min_cost(*stk_b);
		//printf("P 400: min ra=%d,rra=%d,rb=%d,rrb=%d\n", cur_cost.ra, cur_cost.rra, cur_cost.rb, cur_cost.rrb);
		i = 0;
		if (cur_cost.ra)
			while(i++ < cur_cost.ra)
				rotate(stk_a, 'a');
		else
			while(i++ < cur_cost.rra)
				rev_rotate(stk_a, 'a');
		i = 0;
		if (cur_cost.rb)
			while(i++ < cur_cost.rb)
				rotate(stk_b, 'b');
		else
			while(i++ < cur_cost.rrb)
				rev_rotate(stk_b, 'b');
		push_a(stk_a, stk_b);
		/*
		// PRINT NODES & IDX
    	printf("\nStk_A\tidx\n");
    	node_a = *stk_a;
		while (node_a != NULL)
		{
			printf("%d\t%d\n", node_a->content, node_a->idx);
			node_a = node_a -> next;
		}
    	node_b = *stk_b;
    	printf("Stk_B\tidx\n");
    	while (node_b != NULL)
		{
			printf("%d\t%d\n", node_b->content, node_b->idx);
			node_b = node_b -> next;
		}
		*/
	}
	return ;
}

void	set_cost(t_list *stk_a, t_list *stk_b)
{
	int		i;
	int		j;
	int		size[2];
	t_list	*node_a;
	t_list	*node_b;
	int		target;
	
	set_cost_zero(stk_b);
	size[0] = ftps_lstsize(stk_a);
	size[1] = ftps_lstsize(stk_b);
	node_b = stk_b;
	i = 0;
	while(node_b != NULL)
	{
		if (i <= size[1] / 2 && size[1] != 1)
			node_b->cost.rb = i;
		else if (size[1] != 1)
			node_b->cost.rrb = size[1] - i;
		target = (node_b->idx);
		node_a = stk_a;
		j = 0;
		if (max_idx(node_a) < target)
			j = size[0];
		else if (node_a->idx < target)
		{
			while(node_a->idx < target)
			{
				j++;
				node_a = node_a->next;
			}
		}
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