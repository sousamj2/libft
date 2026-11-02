/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:42:52 by marisous          #+#    #+#             */
/*   Updated: 2026/11/02 16:47:36 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* typedef struct s_list */
/* { */
/* 	void			*content; */
/* 	struct s_list	*next; */
/* }				t_list; */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	if (lst == NULL)
		return (0);
	return (1 + ft_lstsize(lst->next));
}
