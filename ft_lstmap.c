/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:57:47 by marisous          #+#    #+#             */
/*   Updated: 2026/11/02 20:15:34 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*retval;
	t_list	*newlist;

	if (lst == NULL)
		return (NULL);
	newlist = ft_lstnew(f(lst->content));
	if (newlist == NULL)
		return (NULL);
	retval = newlist;
	while (lst->next != NULL)
	{
		newlist->next = ft_lstnew(f(lst->next->content));
		if (newlist->next == NULL)
		{
			ft_lstclear(&retval, del);
			return (NULL);
		}
		newlist = newlist->next;
		lst = lst->next;
	}
	newlist->next = NULL;
	return (retval);
}
