/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 22:49:58 by marisous          #+#    #+#             */
/*   Updated: 2026/11/04 15:39:01 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/**
 * @brief Computes length of substring safely against bounds of string s.
 *
 * @param s Source string.
 * @param start Start index in s.
 * @param len Desired substring length.
 * @return Number of characters that can be extracted without exceeding bounds.
 */
static size_t	ft_size_alloc(char const *s, unsigned int start, size_t len)
{
	size_t	size_str;

	size_str = ft_strlen(s);
	if (size_str <= start)
		return (0);
	else if (size_str < len + start)
		return (size_str - start);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*retval;
	unsigned int	index;
	size_t			size_alloc;

	if (s == NULL)
		return (NULL);
	size_alloc = ft_size_alloc(s, start, len);
	retval = ft_calloc(size_alloc + 1, sizeof(char));
	if (retval == NULL)
		return (NULL);
	if (!size_alloc)
		return (retval);
	index = 0;
	s += start;
	while (index < size_alloc)
	{
		*retval = *s;
		s++;
		*(retval + 1) = '\0';
		retval++;
		index++;
	}
	return (retval - index);
}
