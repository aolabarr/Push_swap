/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:03:50 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/08 13:16:33 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exe_movements(t_list **stk_a, t_list **stk_b, t_cost cur_cost)
{
	int	i;

	if (cur_cost.ra && cur_cost.rb)
		cur_cost = exe_double_rot(stk_a, stk_b, cur_cost);
	if (cur_cost.rra && cur_cost.rrb)
		cur_cost = exe_double_rev_rot(stk_a, stk_b, cur_cost);
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

t_cost	exe_double_rot(t_list **stk_a, t_list **stk_b, t_cost cur_cost)
{
	int	rpt;
	int	i;

	i = 0;
	rpt = max(cur_cost.ra, cur_cost.rb) - abs(cur_cost.ra - cur_cost.rb);
	while (i++ < rpt)
		rotate_double(stk_a, stk_b, NO_WRITE);
	if (cur_cost.ra > cur_cost.rb)
	{
		cur_cost.ra = cur_cost.ra - cur_cost.rb;
		cur_cost.rb = 0;
	}
	else if (cur_cost.ra < cur_cost.rb)
	{
		cur_cost.rb = cur_cost.rb - cur_cost.ra;
		cur_cost.ra = 0;
	}
	else
	{
		cur_cost.ra = 0;
		cur_cost.rb = 0;
	}
	return (cur_cost);
}

t_cost	exe_double_rev_rot(t_list **stk_a, t_list **stk_b, t_cost cur_cost)
{
	int	rpt;
	int	i;

	i = 0;
	rpt = max(cur_cost.rra, cur_cost.rrb) - abs(cur_cost.rra - cur_cost.rrb);
	while (i++ < rpt)
		rotate_double(stk_a, stk_b, NO_WRITE);
	if (cur_cost.rra > cur_cost.rrb)
	{
		cur_cost.rra = cur_cost.rra - cur_cost.rrb;
		cur_cost.rrb = 0;
	}
	else if (cur_cost.rra < cur_cost.rrb)
	{
		cur_cost.rrb = cur_cost.rrb - cur_cost.rra;
		cur_cost.rra = 0;
	}
	else
	{
		cur_cost.rra = 0;
		cur_cost.rrb = 0;
	}
	return (cur_cost);
}
