/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:23:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/05/01 01:29:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack;
	t_list	*head;

	if (ac != 2)
		return (0);
	else if  (ac > 2 || check_errors(av[1]) == -1)
		return (ft_putstr_fd(ERROR_MESSAGE, STDERR), 0);
	stack = create_stack(av[1]);
	put_sorted_index(stack);
	if (stack == NULL)
		return (ft_putstr_fd(ERROR_MESSAGE, STDERR), 0);
	head = stack;
	printf("origin stack\n");
	while (stack -> next != NULL)
	{
		ft_putnbr_fd(stack -> content, STDOUT);
		ft_putchar_fd('\n', STDOUT);
		stack = stack -> next;
	}
	ft_putnbr_fd(stack -> content, STDOUT);
	ft_putchar_fd('\n', STDOUT);
	stack = head;
	/*
	t_list *list;
	int num;

	num = ft_atoi("28");
	printf("%d\n", num);
	list = ftps_lstnew(num);
	printf("%d\n", list->content);
*/
	return (0);
}

t_list	*create_stack(char *str)
{
	t_list	*lst;
	t_list	*node;
	char	**ptr;
	size_t	i;
	size_t	size;

	ptr = ft_split(str, ' ');
	if (!ptr)
		return (NULL);
	i = 0;
	size = ft_matsize(ptr);
	while (i < size)
	{
		if (i == 0)
			lst = ftps_lstnew(ft_atoi(ptr[i]));
		else
		{
			node = ftps_lstnew(ft_atoi(ptr[i])); // si falla malloc liberar ptr y lst
			ftps_lstadd_back(&lst, node);
		}
		i++;
	}
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
		node -> idx = i;
		i++;
	}
	ft_free_array(&array);
	node = stack;
	while (node != NULL)
	{
		printf("%d\t%d\n", node->content, node->idx);
		node = node -> next;
	}
	return ;
}

void	ft_free_mat(char **mat, size_t size)
{
	while (size)
	{
		free(mat[size]);
		size--;
	}
	free(mat[0]);
	free(mat);
	return ;
}

void	ft_free_array(int **array)
{
	if (*array)
		free(*array);
	*array = NULL;
}
