/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 22:22:44 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 07:59:12 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ibyte;
	size_t			index;

	ibyte = (unsigned char *) s;
	index = 0;
	while (index < n)
	{
		if (*ibyte == (unsigned char) c)
			return (ibyte);
		ibyte++;
		index++;
	}
	return (NULL);
}
