/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:57:02 by marisous          #+#    #+#             */
/*   Updated: 2026/10/26 18:50:32 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, t_size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	t_size_t			index;

	ptr_dest = (unsigned char *) dest;
	ptr_src = (const unsigned char *) src;
	index = 0;
	while (index < n)
	{
		*ptr_dest = *ptr_src;
		ptr_src++;
		ptr_dest++;
		index++;
	}
	return (dest);
}
