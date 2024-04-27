/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:39:09 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/27 16:10:21 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAXINT 2147483647
# define MININT -2147483648
# define MAXINT_STR "2147483647"
# define MININT_STR "-2147483648"
# define STDOUT 1
# define STDERR 2
# define ERROR_MESSAGE "Error\n"


# include <unistd.h>
# include <stdlib.h> 
# include "src/libft/libft.h"
# include "src/liblst/liblst.h"

t_list		*create_stack(char *str);
int			check_errors(char *str);
void		ft_free_mat(char **mat, size_t mlen);


#endif
