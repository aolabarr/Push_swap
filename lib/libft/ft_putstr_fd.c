/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:37:25 by aolabarr          #+#    #+#             */
/*   Updated: 2024/05/04 18:03:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	if (ft_strncmp(s, "Error", ft_strlen(s)) != 0)
		return (1);
	else
		return(0);
}
