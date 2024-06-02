/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:13:24 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/02 12:13:24 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_putnbr_fd(t_list *lst, int fd)
{
	t_list	*node;

	if (!lst)
		return ;
	node = lst;
	while (node != NULL)
	{
		ft_putnbr_fd(node -> content, fd);
		ft_putchar_fd('\n', fd);
		node = node -> next;
	}
	return ;
}

int	ft_lst_is_sorted(t_list *lst)
{
	t_list	*node;

	if (!lst)
		return (0);
	else if (ftps_lstsize(lst) == 1)
		return (1);
	node = lst;
	while ((node -> next) != NULL)
	{
		if ((node -> content) > (node -> next -> content))
			return (0);
		node = node -> next;
	}
	return (1);
}

size_t	ft_matsize(char **str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (*str != NULL)
	{
		count++;
		str++;
	}
	return (count);
}
