/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:51:55 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/06 14:34:37 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

int max(int a, int b)
{
    if (a >= b)
        return (a);
    else
        return (b);
}
