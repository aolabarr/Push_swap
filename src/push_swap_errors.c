/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:46:56 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/09 19:40:49 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_errors_str(char *str)
{
	size_t	i;
	char	**ptr;

	if (!str || *str == '\0')
		exit (0);
	ptr = ft_split(str, ' ');
	i = 0;
	while (ptr[i] != NULL)
		if (!ft_str_is_numeric(ptr[i]) || !ft_is_int(ptr[i++]))
			exit (ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO));
	if (!ft_str_norepeat_in_mat(ptr))
		exit (ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO));
	ft_free_mat(ptr);
	return ;
}

void	check_errors_av(int ac, char **ptr)
{
	int	i;

	if (!ptr)
		exit (0);
	i = 1;
	while (i < ac)
		if (!ft_str_is_numeric(ptr[i]) || !ft_is_int(ptr[i++]))
			exit (ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO));
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
	if (ft_strlen(str) >= 10)
		if (ft_strncmp(MAXINT_STR, str, ft_strlen(str)) < 0)
			return (0);
	if (str[0] == '-' && ft_strlen(str) >= 11)
		if (ft_strncmp(MININT_STR, str, ft_strlen(str)) < 0)
			return (0);
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
