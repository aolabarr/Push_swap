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

void    manage_push_swap(t_list **stack)
{
    int size;
    //t_list *orders;

    if (ft_lst_is_sorted(*stack) || ftps_lstsize(*stack) == 1)
        exit(0);
    size = ftps_lstsize(*stack);
    if (size == 2)
        sort_2stack(stack);
    else if (size == 3)
        sort_3stack(stack);
    else
        push_swap(stack);
}

void    push_swap(t_list **stack_a)
{
    t_list  **stack_b;
    //t_list  *orders;
    t_list  *node_a;
    t_list  *node_b;
    
    stack_b = malloc(sizeof(t_list *));
    if (!stack_b)
        exit(1);
    *stack_b = NULL;
    fill_stackb(stack_a, stack_b);
    
    // PRINT NODES & IDX
    printf("\nStk_A\tidx\n");
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
    while (j < size - 3)
    {
        if ((*stk_a)->idx <= size / PARTS * (i + 1))
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

void    sort_2stack(t_list **stk_a)
{
    //t_list *orders;

    swap(stk_a, 'a');
    return ;
}

void    sort_3stack(t_list **stk)
{
    int a;
    int b;
    int c;

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
