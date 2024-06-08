/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:20:26 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/08 19:22:48 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

int	main(int ac, char** av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**ords;
	size_t	i;

	stack_a = manage_input_data(ac, av);
	stack_b = malloc(sizeof(t_list *));
	if (!stack_b)
		exit(1);
	stack_b = NULL;
	ords = read_stdin();
	i = 0;
	while (i < ft_matsize(ords))
	{
		exe_order(&stack_a, &stack_b, ords[i]);
		i++;
	}
	if (ft_lst_is_sorted(stack_a) && stack_b == NULL)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	return (0);
}

char	**read_stdin(void)
{
	char	*str;
	char	buffer[BUFFER_SIZE];
	int		read_bytes;
	char	**ords;

	read_bytes = 1;
	str = ft_strdup("");
	while (read_bytes > 0)
	{
		read_bytes = read(STDIN_FILENO, buffer, BUFF_SIZE);
		//printf("%d\n", read_bytes);
		str = ft_strjoin_freed(str, buffer);
	}
	ords = ft_split(str, '\n');
	return (ords);
}

void	exe_order(t_list **stack_a, t_list **stack_b, char *ord)
{
	if (!ft_strncmp(ord,"sa",ft_strlen("sa")))
		swap_bn(stack_a);
	else if (!ft_strncmp(ord,"sb",ft_strlen("sb")))
		swap_bn(stack_b);
	else if (!ft_strncmp(ord,"pa",ft_strlen("pa")))
		push_a_bn(stack_a, stack_b);
	else if (!ft_strncmp(ord,"pb",ft_strlen("pb")))
		push_b_bn(stack_a, stack_b);
	else if (!ft_strncmp(ord,"ra",ft_strlen("ra")))
		rotate_bn(stack_a);
	else if (!ft_strncmp(ord,"rb",ft_strlen("rb")))
		rotate_bn(stack_b);
	else if (!ft_strncmp(ord,"rra",ft_strlen("rra")))
		rev_rotate_bn(stack_a);
	else if (!ft_strncmp(ord,"rrb",ft_strlen("rrb")))
		rev_rotate_bn(stack_b);
	else if (!ft_strncmp(ord,"ss",ft_strlen("ss")))
		swap_double_bn(stack_a, stack_b);
	else if (!ft_strncmp(ord,"rr",ft_strlen("rr")))
		rotate_double_bn(stack_a, stack_b);
	else if (!ft_strncmp(ord,"rrr",ft_strlen("rrr")))
		rev_rotate_double_bn(stack_a, stack_b);
	return ;
}
