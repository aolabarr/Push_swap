/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:23:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/10 11:25:20 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*manage_input_data(int ac, char **av)
{
	t_list	*stack;
	char	**ptr;

	stack = NULL;
	if (ac < 2)
		exit (EXITCODE);
	else if (ac == 2)
		ptr = ft_split(av[1], ' ');
	else if (ac > 2)
		ptr = copy_arguments(ac, av);
	if (!ptr)
		exit(EXITCODE);
	/*
	size_t i = 0;
	printf("prueba 0\n");
	while (i < ft_matsize(ptr))
	{
		printf("%s\n", ptr[i]);
		i++;
	}
	*/
	//printf("prueba 1\n");
	check_errors(ptr);
	//printf("prueba 2\n");
	stack = create_stack(ptr);
	ft_free_mat(ptr, ft_matsize(ptr));
	//printf("prueba 3\n");
	//ft_lst_putnbr_fd(stack, STDOUT_FILENO);
	return (stack);
}

t_list	*create_stack(char **ptr)
{
	t_list	*lst;
	t_list	*node;
	size_t		i;

	i = 0;
	lst = ftps_lstnew(ft_atoi(ptr[i++]));
	if (!lst)
		exit(EXITCODE);
	while (i < ft_matsize(ptr))
	{
		node = ftps_lstnew(ft_atoi(ptr[i++]));
		if (!node)
		{
			ftps_lstclear(&lst, &free);
			exit(EXITCODE);
		}	
		ftps_lstadd_back(&lst, node);
	}
	if (ptr[0] != NULL)
		put_sorted_index(lst);
	return (lst);
}

char	**copy_arguments(int ac, char **av)
{
	char	**ptr;
	int		i;

	ptr = malloc(ac * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	//printf("ac: %d\n", ac);
	while (i < ac - 1)
	{
		ptr[i] = malloc(sizeof(char *));
		if (!ptr[i])
			return (ft_free_mat(ptr, i), NULL);
		ft_strlcpy(ptr[i], av[i + 1], ft_strlen(av[i + 1]) + 1);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
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
