/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 08:19:12 by marisous          #+#    #+#             */
/*   Updated: 2026/10/28 14:52:49 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	size_dst;
	size_t	size_src;

	size_dst = ft_strlen(dst);
	if (size < 1)
		return (size_dst);
	size_src = ft_strlen(src);
	index = 0;
	while (size_dst + index < size - 1 && src[index] != '\0')
	{
		dst[size_dst + index] = src[index];
		dst[size_dst + index + 1] = '\0';
		index++;
	}
	if (size_dst + size_src <= size)
		return (size_dst + size_src);
	if (size <= size_dst)
		return
			(size_dst + size);
	return (size_dst + (size - index) - 1);
}
