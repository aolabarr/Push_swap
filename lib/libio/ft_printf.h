/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:19:11 by aolabarr          #+#    #+#             */
/*   Updated: 2024/01/27 13:53:36 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
int		ft_putnbr(int n);
int		ft_putnbru(unsigned int u);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int		ft_printf(const char *str, ...);
char	*ft_itoahex(size_t n);
char	*ft_strupcase(char *str);

int		manage_char(int c);
int		manage_str(char *str);
int		manage_hex(unsigned int num, char c);
int		manage_dir(size_t num);

#endif
