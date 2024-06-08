/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:50:14 by aolabarr          #+#    #+#             */
/*   Updated: 2024/01/27 16:37:54 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	manage_str(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	manage_hex(unsigned int num, char c)
{
	char	*str;
	char	*dst;
	int		len;

	dst = NULL;
	str = ft_itoahex(num);
	if (!str)
		return (0);
	if (c == 'X')
		dst = ft_strupcase(str);
	else if (c == 'x')
		dst = str;
	len = manage_str(dst);
	free(dst);
	return (len);
}

int	manage_dir(size_t num)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoahex(num);
	if (!str)
		return (0);
	len += manage_str("0x");
	len += manage_str(str);
	free(str);
	return (len);
}
