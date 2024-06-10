/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:53:30 by aolabarr          #+#    #+#             */
/*   Updated: 2024/05/03 15:53:58 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_push_swap(t_list **stack)
{
	int	size;

	if (ft_lst_is_sorted(*stack) || ftps_lstsize(*stack) == 1)
		exit(0);
	size = ftps_lstsize(*stack);
	if (size == 2)
		sort_2stack(stack);
	else if (size == 3)
		sort_3stack(stack);
	else if (size == 5)
		sort_5stack(stack);
	else
		push_swap(stack);
}

void	push_swap(t_list **stack_a)
{
	t_list	**stack_b;

	stack_b = malloc(sizeof(t_list *));
	if (!stack_b)
		exit(EXITCODE);
	*stack_b = NULL;
	fill_stackb(stack_a, stack_b);
	sort_3stack(stack_a);
	empty_stackb(stack_a, stack_b);
	free(stack_b);
	final_sort(stack_a);
}

void	fill_stackb(t_list **stk_a, t_list **stk_b)
{
	int	mc;
	int	size;
	int	i;
	int	j;

	size = ftps_lstsize(*stk_a);
	if (size / PARTS > 0)
		mc = size / PARTS;
	else
		mc = size;
	i = 0;
	j = 0;
	while (j < size - 3)
	{
		if ((*stk_a)->idx <= mc * (i + 1))
		{
			push_b(stk_a, stk_b);
			j++;
		}
		else
			rotate(stk_a, 'a');
		if (j >= mc * (i + 1))
			i++;
	}
}

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
			rotate(stk, 'a');
	}
	else
	{
		while ((*stk)->idx != 1)
			rev_rotate(stk, 'a');
	}
	return ;
}
