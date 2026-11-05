/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 19:19:10 by marisous          #+#    #+#             */
/*   Updated: 2026/11/05 13:22:13 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*retval;

	if (n > SIZE_MAX / size)
		return (NULL);
	retval = malloc(n * size);
	if (retval == NULL)
		return (NULL);
	ft_bzero(retval, n * size);
	return (retval);
}
