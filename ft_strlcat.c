/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 08:19:12 by marisous          #+#    #+#             */
/*   Updated: 2026/10/27 13:08:42 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	size_dst;

	size_dst = ft_strlen(dst);
	index = 0;
	while (size_dst + index < size_dst + size - 1 && src[index] != '\0')
	{
		dst[size_dst + index] = src[index];
		dst[size_dst + index + 1] = '\0';
		index++;
	}
	while (index < size)
	{
		dst[size_dst + index] = '\0';
		index++;
	}
	return (ft_strlen(dst));
}
