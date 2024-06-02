/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_arrays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:12:44 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/02 13:32:52 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_array(t_list *stack)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * ftps_lstsize(stack));
	if (!array)
		return (NULL);
	i = 0;
	while (stack != NULL)
	{
		array[i] = stack -> content;
		stack = stack -> next;
		i++;
	}
	return (array);
}

void	ft_bubble_sort(int *array, int size)
{
	int	i;

	while (!ft_array_is_sorted(array, size))
	{
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
				ft_swap_nbr(&array[i], &array[i + 1]);
			i++;
		}
	}
	return ;
}

int	ft_array_is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_swap_nbr(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}
