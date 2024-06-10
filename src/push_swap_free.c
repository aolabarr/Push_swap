/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:13:13 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/02 12:13:13 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_mat(char **mat, size_t size)
{
	while (size)
	{
		free(mat[size]);
		size--;
	}
	free(mat[0]);
	free(mat);
	return ;
}

void	ft_free_array(int **array)
{
	if (*array)
		free(*array);
	*array = NULL;
}
