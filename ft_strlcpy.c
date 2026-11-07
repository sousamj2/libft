/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 07:05:41 by marisous          #+#    #+#             */
/*   Updated: 2026/11/07 16:38:34 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (dst == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	index = 0;
	if (src[index] == '\0' || size == 1)
		dst[index] = '\0';
	while (index < size - 1 && src[index] != '\0')
	{
		dst[index] = src[index];
		dst[index + 1] = '\0';
		index++;
	}
	return (ft_strlen(src));
}
