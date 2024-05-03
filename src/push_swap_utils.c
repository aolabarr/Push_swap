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

void    push_swap(t_list **stack_a)
{
    t_list  **stack_b;
    //t_list  *orders;
    t_list  *node_a;
    t_list  *node_b;
    
    printf("Stack_inicial\n");
    ft_lst_putnbr_fd(*stack_a, STDOUT);
    stack_b = malloc(sizeof(t_list *));
    *stack_b = NULL;
    //printf("stk_b dir: %p\n", stack_b);
    fill_stackb(stack_a, stack_b);
    
    // PRINT NODES & IDX
    //ft_lst_putnbr_fd(*stack_a, STDOUT);
    printf("Stk_A\tidx\n");
    node_a = *stack_a;
	while (node_a != NULL)
	{
		printf("%d\t%d\n", node_a->content, node_a->idx);
		node_a = node_a -> next;
	}
    node_b = *stack_b;
    printf("Stk_B\tidx\n");
    while (node_b != NULL)
	{
		printf("%d\t%d\n", node_b->content, node_b->idx);
		node_b = node_b -> next;
	}
    sort_3stack(stack_a);
    /*
    while(!ftps_lstsize(*stack_b))
        move_one(stack_a, stack_b);
    return (orders);
    */
}

void    fill_stackb(t_list **stk_a, t_list **stk_b)
{
    int  size;
    int  mc;
    int  i;
    int  j;

    
    size = ftps_lstsize(*stk_a);
    mc = size / PARTS;
    i = 0;
    j = 0;
    //printf("P: 0000\n");
    while (j < size - 2)
    {
        if ((*stk_a)->idx <= size / PARTS * (i + 1))
        {
            push_b(stk_a, stk_b);
            j++;
        }
        //else
            //rotate(stk_a, 'a');
        if (j > mc * (i + 1))
        {
            printf("P: 5000\n");
            i++;
        }
    }
}

void    sort_3stack(t_list **stk_a)
{
    if (!ft_lst_is_sorted(*stk_a))
        swap(stk_a, 'a');
    return;
}
