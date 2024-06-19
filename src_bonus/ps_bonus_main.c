/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:20:26 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/19 11:57:43 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	**stack_b;
	char	**ords;

	ords = read_stdin();
	if (!ords)
		exit(EXITCODE);
	stack_a = manage_input_data(ac, av);
	stack_b = malloc(sizeof(t_list *));
	if (!stack_b)
		exit(EXITCODE);
	*stack_b = NULL;
	handle_orders(&stack_a, stack_b, ords);
	ft_free_mat(ords, ft_matsize(ords));
	write_result(stack_a, *stack_b);
	ftps_lstclear(&stack_a, &free);
	ftps_lstclear(stack_b, &free);
	free(stack_a);
	free(stack_b);
	return (0);
}

char	**read_stdin(void)
{
	char	*str;
	char	buffer[BUFFER_SIZE + 1];
	int		read_bytes;
	char	**ords;

	read_bytes = 1;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (read_bytes > 0)
	{
		read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(str), NULL);
		buffer[read_bytes] = '\0';
		str = ft_strjoin_freed(str, buffer);
		if (!str)
			return (NULL);
	}
	ords = ft_split(str, '\n');
	if (!ords)
		return (free(str), NULL);
	free (str);
	return (ords);
}

void	exe_order(t_list **stack_a, t_list **stack_b, char *ord)
{
	if (!ft_strncmp(ord, "sa", ft_strlen("sa")))
		swap_bn(stack_a);
	else if (!ft_strncmp(ord, "sb", ft_strlen("sb")))
		swap_bn(stack_b);
	else if (!ft_strncmp(ord, "pa", ft_strlen("pa")))
		push_a_bn(stack_a, stack_b);
	else if (!ft_strncmp(ord, "pb", ft_strlen("pb")))
		push_b_bn(stack_a, stack_b);
	else if (!ft_strncmp(ord, "ra", ft_strlen("ra")))
		rotate_bn(stack_a);
	else if (!ft_strncmp(ord, "rb", ft_strlen("rb")))
		rotate_bn(stack_b);
	else if (!ft_strncmp(ord, "rra", ft_strlen("rra")))
		rev_rotate_bn(stack_a);
	else if (!ft_strncmp(ord, "rrb", ft_strlen("rrb")))
		rev_rotate_bn(stack_b);
	else if (!ft_strncmp(ord, "ss", ft_strlen("ss")))
		swap_double_bn(stack_a, stack_b);
	else if (!ft_strncmp(ord, "rrr", ft_strlen("rrr")))
		rev_rotate_double_bn(stack_a, stack_b);
	else if (!ft_strncmp(ord, "rr", ft_strlen("rr")))
		rotate_double_bn(stack_a, stack_b);
	return ;
}

void	write_result(t_list *stack_a, t_list *stack_b)
{
	if (ft_lst_is_sorted(stack_a) && stack_b == NULL)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	return ;
}

void	handle_orders(t_list **stack_a, t_list **stack_b, char **ords)
{
	size_t	i;

	i = 0;
	while (i < ft_matsize(ords))
	{
		exe_order(stack_a, stack_b, ords[i]);
		i++;
	}
	return ;
}
