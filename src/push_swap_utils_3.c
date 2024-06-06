/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:06:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/06 14:34:52 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	sort_2stack(t_list **stk_a)
{
	swap(stk_a, 'a');
	return ;
}

void	sort_3stack(t_list **stk)
{
	int	a;
	int	b;
	int	c;

	a = (*stk)->content;
	b = (*stk)->next->content;
	c = (*stk)->next->next->content;
	if (a > b && b < c && a < c)
		swap(stk, 'a');
	else if (a > b && b > c)
	{
		swap(stk, 'a');
		rev_rotate(stk, 'a');
	}
	else if (a > b && b < c && a > c)
		rotate(stk, 'a');
	else if (a < b && b > c && a < c)
	{
		swap(stk, 'a');
		rotate(stk, 'a');
	}
	else if (a < b && b > c && a > c)
		rev_rotate(stk, 'a');
	return ;
}

void    sort_5stack(t_list **stk_a)
{
   t_list  **stk_b;
    
    stk_b = malloc(sizeof(t_list *));
    if (!stk_b)
        exit(1);
    *stk_b = NULL;
    push_b(stk_a, stk_b);
    push_b(stk_a, stk_b);
    sort_3stack(stk_a);
    empty_stackb(stk_a, stk_b);
    ftps_lstclear(stk_b, &free);
    final_sort(stk_a);
    return ;
}
