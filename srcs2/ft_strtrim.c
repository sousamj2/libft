/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 07:10:38 by marisous          #+#    #+#             */
/*   Updated: 2026/10/31 13:04:27 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <strings.h>

static size_t	ft_count_mem_size(char const *s1, char const *set)
{
	const char	*it_set;
	size_t		count;
	int			skip;

	count = ft_strlen(s1);
	while (*s1 != '\0')
	{
		it_set = set;
		skip = 0;
		while (*it_set != '\0')
		{
			if (*s1 == *it_set)
			{
				skip = 1;
				break ;
			}
			it_set++;
		}
		if (skip)
			count--;
		s1++;
	}
	return (count);
}

static char	*ft_prepare_mem(char const *s1, char const *set, size_t *size_alloc)
{
	char	*retval;

	if (!s1 || !set)
		return (NULL);
	*size_alloc = ft_count_mem_size(s1, set);
	retval = malloc((1 + *size_alloc) * sizeof(char));
	if (!retval)
		return (NULL);
	bzero(retval, *size_alloc + 1);
	return (retval);
}

static char	*ft_prepare_retval(char const *s1, char const *set, char *retval)
{
	const char	*it_set;
	int			skip;

	while (*s1 != '\0')
	{
		it_set = set;
		skip = 0;
		while (*it_set != '\0')
		{
			if (*s1 == *it_set)
			{
				skip = 1;
				break ;
			}
			it_set++;
		}
		if (!skip)
		{
			*retval = *s1;
			retval++;
		}
		s1++;
	}
	return (retval);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*retval;
	size_t	size_alloc;

	retval = ft_prepare_mem(s1, set, &size_alloc);
	if (!retval)
		return (NULL);
	retval = ft_prepare_retval(s1, set, retval);
	return (retval - size_alloc);
}
