/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:23:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/05/03 15:34:53 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack;
	t_list	*node;
	//t_list	*orders;

	if (ac != 2)
		return (0);
	else if  (ac > 2 || check_errors(av[1]) == -1)
		return (ft_putstr_fd(ERROR_MESSAGE, STDERR), 0);
	stack = create_stack(av[1]);
	if (stack == NULL)
		return (ft_putstr_fd(ERROR_MESSAGE, STDERR), 0);
	push_swap(&stack);
	//ftps_lstsize(orders);

	// PRINT NODES & IDX
	printf("MAIN\nNode\tidx\n");
	node = stack;
	while (node != NULL)
	{
		printf("%d\t%d\n", node->content, node->idx);
		node = node -> next;
	}
	//
	return (0);
}

t_list	*create_stack(char *str)
{
	t_list	*lst;
	t_list	*node;
	char	**ptr;
	size_t	i;

	ptr = ft_split(str, ' ');
	if (!ptr)
		return (NULL);
	i = 0;
	lst = ftps_lstnew(ft_atoi(ptr[i++]));
	if (!lst)
		return (ft_free_mat(ptr), NULL);
	while (i < ft_matsize(ptr))
	{
		node = ftps_lstnew(ft_atoi(ptr[i++]));
		if (!node)
			return (ft_free_mat(ptr), ftps_lstclear(&lst, &free), NULL);
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
