/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:37:25 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/02 12:04:40 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	if (ft_strncmp(s, "Error", ft_strlen(s)) != 0)
		return (1);
	else
		return (0);
}
