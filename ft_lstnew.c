/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:29:49 by marisous          #+#    #+#             */
/*   Updated: 2026/11/03 15:40:02 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*retval;

	retval = malloc(sizeof(t_list));
	if (retval == NULL)
		return (NULL);
	retval->next = NULL;
	retval->content = content;
	return (retval);
}
