/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:23:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/05/04 20:08:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack;
	t_list	*node;
	//t_list	*orders;

	
	stack = manage_input_data(ac, av);
	//check_errors(av[1]);
	//stack = create_stack(av[1]);
	//if (stack == NULL)
	//	return (ft_putstr_fd(ERROR_MESSAGE, STDERR));
	
	// Stack incial
    printf("Stack_inicial\n");
    ft_lst_putnbr_fd(stack, STDOUT);
	printf("\nORDERS\n");
	
	manage_push_swap(&stack);
	//ftps_lstsize(orders);

	// PRINT NODES & IDX
	printf("\nMAIN\nNode\tidx\n");
	node = stack;
	while (node != NULL)
	{
		printf("%d\t%d\n", node->content, node->idx);
		node = node -> next;
	}
	//
	return (0);
}

t_list	*manage_input_data(int ac, char **av)
{
	t_list *stack;
	if  (ac < 2)
		exit (0);
	else if (ac == 2)
	{
		check_errors_str(av[1]);
		stack = create_stack_str(av[1]);
	}	
	else if (ac > 2)
	{
		check_errors_av(ac, av);
		stack = create_stack_av(ac, av);
	}
		
	return (stack);
}

t_list	*create_stack_av(int ac, char **ptr)
{
	t_list	*lst;
	t_list	*node;
	int		i;

	if (!ptr)
		exit (EXITCODE);
	i = 1;
	lst = ftps_lstnew(ft_atoi(ptr[i++]));
	if (!lst)
		exit(EXITCODE);
	while (i < ac)
	{
		node = ftps_lstnew(ft_atoi(ptr[i++]));
		if (!node)
			exit(EXITCODE);
		ftps_lstadd_back(&lst, node);
	}
	if (ptr[0] != NULL)
		put_sorted_index(lst);
	return (lst);
}

t_list	*create_stack_str(char *str)
{
	t_list	*lst;
	t_list	*node;
	char	**ptr;
	size_t	i;

	ptr = ft_split(str, ' ');
	if (!ptr)
		exit (EXITCODE);
	i = 0;
	lst = ftps_lstnew(ft_atoi(ptr[i++]));
	if (!lst)
		exit(EXITCODE);
	while (i < ft_matsize(ptr))
	{
		node = ftps_lstnew(ft_atoi(ptr[i++]));
		if (!node)
			exit(EXITCODE);
		ftps_lstadd_back(&lst, node);
	}
	if (ptr[0] != NULL)
		put_sorted_index(lst);
	return (lst);
}

void	put_sorted_index(t_list *stack)
{
	int		*array;
	int		i;
	t_list	*node;

	if (!stack)
		return ;
	array = create_array(stack);
	ft_bubble_sort(array, ftps_lstsize(stack));
	i = 0;
	while (i < ftps_lstsize(stack))
	{
		node = stack;
		while (node->content != array[i])
			node = node -> next;
		node -> idx = i + 1;
		i++;
	}
	ft_free_array(&array);
	return ;
}
