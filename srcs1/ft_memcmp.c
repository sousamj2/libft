/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 08:16:19 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 08:34:07 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*c1;
	unsigned char	*c2;

	index = 0;
	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	while (index < n)
	{
		if (*c1 != *c2)
			return ((int) *c1 - *c2);
		c1++;
		c2++;
		index++;
	}
	return (0);
}
