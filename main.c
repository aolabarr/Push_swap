/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:23:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/13 21:10:03 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	*stack_a;
	int	size_a;
	int	i;

	size_a = 0;
	if (ac == 1)
	{
		ft_putstr_fd(ERROR_MESSAGE, OUTPUT);
		return(0);
	}
	else if (ac == 2)
	{
		stack_a = input_1(av[1], &size_a);
		if (stack_a == NULL)
		{
			ft_putstr_fd(ERROR_MESSAGE, OUTPUT);
			return (0);
		}
	}
	printf("Prueba A\tsize_a = %i\n", size_a);
	i = 0;
	while (i < size_a)
	{
		ft_putnbr_fd(stack_a[i], OUTPUT);
		ft_putstr_fd("\n", OUTPUT);
		i++;
	}
	return (0);
}

int	*input_1(char *str, int *size)
{
	int 	*stack;
	char	**ptr;
	size_t		i;

	ptr = ft_split(str, ' ');
	if (!ptr)
		return (NULL);
	stack = malloc(ft_matlen(ptr) * sizeof(int));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < ft_matlen(ptr))
	{
		/*
		if (!ft_str_is_numeric(ptr[i])) // funcion para verificar que string es un numero
		{
			free(stack); // funcion para liberar puntero
			return (NULL);
		}
		*/
		stack[i] = ft_atoi(ptr[i]);
		i++;
	}
	*size = i;
	return (stack);
}
