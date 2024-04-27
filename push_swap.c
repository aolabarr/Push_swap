/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:23:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/27 16:59:59 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*head;
	int		i;

	stack_a = NULL;
	if (ac == 1)
		return (0);
	else if  (ac > 2 || check_errors(av[1]) == -1)
		return (ft_putstr_fd(ERROR_MESSAGE, STDERR), 0);
	stack_a = create_stack(av[1]);
	if (stack_a == NULL)
		return (ft_putstr_fd(ERROR_MESSAGE, STDERR), 0);

	i = 0;
	head = stack_a;
	while (stack_a -> next != NULL)
	{
		ft_putnbr_fd(stack_a -> content, STDOUT);
		ft_putstr_fd("\n", STDOUT);
		stack_a = stack_a -> next;
	}
	ft_putnbr_fd(stack_a -> content, STDOUT);
	ft_putstr_fd("\n", STDOUT);
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

int	check_errors(char *str)
{
	size_t	i;
	size_t	j;
	char	**ptr;
	size_t	len;

	//printf("PRUEBA 100: %s\n", str);
	if (!str)
		return (-1);
	i = 0;
	//printf("PRUEBA 200\n");
	while (str[i] != '\0')
	{
		if (!(str[i] == '-' || str[i] == '+' || str[i] == ' '))
			if (!(str[i] >= '0' && str[i] <='9'))
				return (printf("PRUEBA 300\n"), -1);
		i++;
	}
	ptr = ft_split(str, ' ');
	len = ft_matlen(ptr);
	i = 0;
	//printf("PRUEBA 400\n");
	while (i < len)
	{
		//printf("PRUEBA 400: %d, %s, %s\n", ft_strncmp(MININT_STR, ptr[i], ft_strlen(ptr[i])), MININT_STR,  ptr[i]);
		if (ft_strlen(ptr[i]) >= 10)
			if (ft_strncmp(MAXINT_STR, ptr[i], ft_strlen(ptr[i])) < 0)
				return (printf("PRUEBA 500\n"), -1);
		if (ptr[i][0] == '-' && ft_strlen(ptr[i]) >= 11)
			if (ft_strncmp(MININT_STR, ptr[i], ft_strlen(ptr[i])) < 0)
				return (printf("PRUEBA 600\n"), -1);
		i++;
	}
	i = 0;
	//printf("PRUEBA 700\n");
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strlen(ptr[i]) == ft_strlen(ptr[j]))
				if (ft_strncmp(ptr[i], ptr[j], ft_strlen(ptr[i])) == 0)
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

t_list	*create_stack(char *str)
{
	t_list	*lst;
	t_list	*node;
	char	**ptr;
	size_t	i;
	size_t	len;

	ptr = ft_split(str, ' ');
	if (!ptr)
		return (NULL);
	i = 0;
	len = ft_matlen(ptr);
	while (i < len)
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

void	ft_free_mat(char **mat, size_t mlen)
{
	while (mlen)
	{
		free(mat[mlen]);
		mlen--;
	}
	free(mat[0]);
	free(mat);
	return ;
}
