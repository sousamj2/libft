/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 07:05:41 by marisous          #+#    #+#             */
/*   Updated: 2026/10/27 08:28:20 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size - 1 && src[index] != '\0')
	{
		dst[index] = src[index];
		dst[index + 1] = '\0';
		index++;
	}
	while (index < size)
	{
		dst[index] = '\0';
		index++;
	}
	return (ft_strlen(src));
}
