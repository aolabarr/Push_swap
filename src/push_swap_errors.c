/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:46:56 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/29 13:12:14 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_errors(char **ptr)
{
	size_t	i;

	if (ptr[0] == NULL)
		exit (ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO));
	i = 0;
	while (i < ft_matsize(ptr))
	{
		if (!ft_str_is_numeric(ptr[i]) || !ft_is_int(ptr[i]))
			exit (ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO));
		i++;
	}
	if (!ft_str_norepeat_in_mat(ptr))
		exit (ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO));
	return ;
}

int	ft_str_is_numeric(char *str)
{
	if (*str == '\0')
		return (0);
	if ((*str == '-' || *str == '+') && !ft_isdigit(*(str + 1)))
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_is_int(char *str)
{
	if (str[0] != '-' && ft_strlen(str) > 10)
		return (0);
	else if (str[0] != '-' && ft_strlen(str) == 10)
	{
		if (ft_strncmp(MAXINT_STR, str, ft_strlen(str)) < 0)
			return (0);
	}
	else if (str[0] == '-' && ft_strlen(str) > 11)
		return (0);
	else if (str[0] == '-' && ft_strlen(str) == 11)
	{
		if (ft_strncmp(MININT_STR, str, ft_strlen(str)) < 0)
			return (0);
	}
	return (1);
}

int	ft_str_norepeat_in_mat(char **ptr)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_matsize(ptr);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strlen(ptr[i]) == ft_strlen(ptr[j]))
				if (ft_strncmp(ptr[i], ptr[j], ft_strlen(ptr[i])) == 0)
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}
