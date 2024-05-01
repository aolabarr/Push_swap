/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftps_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:54:46 by aolabarr          #+#    #+#             */
/*   Updated: 2024/05/01 20:07:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_list	*ftps_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> idx = 0;
	node -> content = content;
	node -> next = NULL;
	return (node);
}
