/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 08:19:12 by marisous          #+#    #+#             */
/*   Updated: 2026/11/07 22:55:21 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the minimum of two size_t values.
 *
 * @param val1 First value.
 * @param val2 Second value.
 * @return Smaller of val1 and val2.
 */
static size_t	ft_getmin(size_t val1, size_t val2);

static size_t	ft_getmin(size_t val1, size_t val2)
{
	if (val1 > val2)
		return (val2);
	else
		return (val1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	size_dst;
	size_t	size_src;

	if (dst == NULL || src == NULL)
		return (0);
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size < 1)
		return (size_src);
	index = 0;
	while (size_dst + index + 1 < size && src[index] != '\0')
	{
		dst[size_dst + index] = src[index];
		dst[size_dst + index + 1] = '\0';
		index++;
	}
	return (ft_getmin(size_dst, size) + size_src);
}
