/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:40:19 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/27 13:32:17 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLST_H
# define LIBLST_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

t_list	*ftps_lstnew(int content);
void	ftps_lstadd_front(t_list **lst, t_list *new);
int		ftps_lstsize(t_list *lst);
t_list	*ftps_lstlast(t_list *lst);
void	ftps_lstadd_back(t_list **lst, t_list *new);
void	ftps_lstdelone(t_list *lst, void (*del)(void *));
void	ftps_lstclear(t_list **lst, void (*del)(void *));
void	ftps_lstiter(t_list *lst, void (*f)(void *));
t_list	*ftps_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
