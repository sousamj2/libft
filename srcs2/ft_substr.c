/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 22:49:58 by marisous          #+#    #+#             */
/*   Updated: 2026/10/31 11:44:42 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_size_alloc(char const *s, unsigned int start, size_t len)
{
	int	size_str;

	size_str = ft_strlen(s);
	if (size_str - (int) start < 0)
		return (0);
	else if (size_str - (int) start < (int) len)
		return (size_str - (int) start);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*retval;
	unsigned int	index;
	size_t			size_alloc;

	if (!s)
		return (NULL);
	size_alloc = ft_size_alloc(s, start, len);
	retval = malloc(size_alloc + 1);
	if (!retval)
		return (NULL);
	ft_bzero(retval, size_alloc + 1);
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
