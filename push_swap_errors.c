/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:46:56 by aolabarr          #+#    #+#             */
/*   Updated: 2024/05/01 00:23:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	len = ft_matsize(ptr);
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

int	ft_str_is_numeric(char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
	}
	return (1);
}
