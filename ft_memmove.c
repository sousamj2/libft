/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 19:01:56 by marisous          #+#    #+#             */
/*   Updated: 2026/11/07 22:54:43 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies n bytes safely between overlapping memory regions.
 *
 * @param dest Destination memory pointer.
 * @param src Source memory pointer.
 * @param n Number of bytes to copy.
 * @return Pointer to dest.
 */
static unsigned char	*ft_overlap(unsigned char *dest,
							const unsigned char *src, size_t n);

static unsigned char	*ft_overlap(unsigned char *dest,
							const unsigned char *src, size_t n)
{
	size_t	iter;

	if (dest > src)
	{
		iter = n;
		while (iter > 0)
		{
			iter--;
			*(dest + iter) = *(src + iter);
		}
	}
	else
	{
		iter = 0;
		while (iter < n)
		{
			*(dest + iter) = *(src + iter);
			iter++;
		}
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	ptr_dest = (unsigned char *) dest;
	ptr_src = (const unsigned char *) src;
	if (dest < src + n || src < dest + n)
		return (ft_overlap(ptr_dest, ptr_src, n));
	else
		return (ft_memcpy(dest, src, n));
}
