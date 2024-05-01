#include "push_swap.h"

void swap(t_list **stack, char id)
{
    t_list *tmp;
    t_list *node;

    node = *stack;
    tmp = node->next->next;
    node->next->next = *stack;
    *stack = node->next;
    (*stack)->next = tmp;
    if (id == 'a')
        ft_putstr_fd("sa\n", 1);
    else if (id == 'b')
        ft_putstr_fd("sb\n", 1);
    return ;
}

void rotate(t_list *stack, char id)
{
    t_list *tmp;

    tmp = stack->next;
    (ftps_lstlast(stack))->next = stack;
    stack -> next = NULL;
    stack = tmp;
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

void    push_b(t_list *stack_a, t_list *stack_b)
{
    t_list *tmp;

    tmp = stack_b -> next;
    stack_b -> next = stack_a;
    stack_a = stack_b;
    stack_b = tmp;
    ft_putstr_fd("pb\n", STDOUT);
    return ;
}

void    push_a(t_list *stack_b, t_list *stack_a)
{
    t_list *tmp;

    tmp = stack_a -> next;
    stack_a -> next = stack_b;
    stack_b = stack_a;
    stack_a = tmp;
    ft_putstr_fd("pa\n", STDOUT);
    return ;
}