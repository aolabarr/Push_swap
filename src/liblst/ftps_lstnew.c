/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftps_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:54:46 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/27 13:32:21 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

t_list	*ftps_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}
