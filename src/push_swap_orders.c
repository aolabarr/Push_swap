

#include "push_swap.h"

void swap(t_list **stk, char id)
{
    t_list  *tmp1;
    t_list  *tmp2;

    if (ftps_lstsize(*stk) == 1)
        return ;
    tmp1 = (*stk)->next;
    tmp2 = (*stk)->next->next;
    (*stk)->next->next = (*stk);
    (*stk)->next = tmp2;
    *stk = tmp1;
    if (id == 'a')
        ft_putstr_fd("sa\n", STDOUT);
    else if (id == 'b')
        ft_putstr_fd("sb\n", STDOUT);
    return ;
}

void rotate(t_list **stk, char id)
{
    // ESA FUNCION ESTA MAL
    t_list *tmp;

    tmp = (*stk)->next;
    (ftps_lstlast(*stk))->next = *stk;
    (*stk)->next = NULL;
    *stk = tmp;
    if (id == 'a')
        ft_putstr_fd("ra\n", STDOUT);
    else if (id == 'b')
        ft_putstr_fd("rb\n", STDOUT);
    return ;
}

void rev_rotate(t_list *stack, char id)
{
    t_list *tmp;
    t_list *node;
    int i;
    
    node = stack;
    i = 1;
    while (i < ftps_lstsize(stack) - 1)
    {
        node = node -> next;
        i++;
    }
    tmp = stack;
    stack = ftps_lstlast(stack);
    ftps_lstlast(stack) -> next = tmp;
    node -> next = NULL;
    if (id == 'a')
        ft_putstr_fd("rra\n", STDOUT);
    else if (id == 'b')
        ft_putstr_fd("rrb\n", STDOUT);
    return ;
}

void    push_a(t_list **stk_a, t_list **stk_b)
{
    t_list *tmp;
    
    tmp = (*stk_b)->next;
    (*stk_b)->next = *stk_a;
    *stk_a = *stk_b;
    *stk_b = tmp;
    ft_putstr_fd("pa\n", STDOUT);
    return ;
}

void    push_b(t_list **stk_a, t_list **stk_b)
{
    t_list *tmp;
    
    if (*stk_b == NULL)
    {
        *stk_b = *stk_a;
        *stk_a = (*stk_a)->next;
        (*stk_b)->next = NULL;
    }
    else
    {
        tmp = (*stk_a) -> next;
        (*stk_a) -> next = *stk_b;
        *stk_b = *stk_a;
        *stk_a = tmp;
    }
    ft_putstr_fd("pb\n", STDOUT);
    return ;
}