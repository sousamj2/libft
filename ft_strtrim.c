/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 07:10:38 by marisous          #+#    #+#             */
/*   Updated: 2026/11/07 12:06:32 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>

/**
 * @brief Finds the first index in s1 that does not contain a character in set.
 *
 * @param s1 Source string.
 * @param set Set of characters to trim.
 * @return Index of first non-matching character, or strlen(s1) if all match.
 */
static unsigned int	ft_find_start(char const *s1, char const *set)
{
	unsigned int	retval;
	const char		*it_set;
	int				stop;

	retval = 0;
	while (*s1 != '\0')
	{
		it_set = set;
		stop = 1;
		while (*it_set != '\0')
		{
			if (*s1 == *it_set)
			{
				stop = 0;
				retval++;
				break ;
			}
			it_set++;
		}
		if (stop)
			return (retval);
		s1++;
	}
	return (retval);
}

/**
 * @brief Counts characters from the end of s1 that are present in set.
 *
 * @param s1 Source string.
 * @param set Set of characters to trim.
 * @return Number of trailing characters to trim.
 */
static size_t	ft_find_stop(char const *s1, char const *set)
{
	size_t		retval;
	const char	*it_set;
	int			stop;

	retval = 0;
	while (*s1 != '\0')
	{
		it_set = set;
		stop = 1;
		while (*it_set != '\0')
		{
			if (*(s1 + ft_strlen(s1) - 1 - retval) == *it_set)
			{
				stop = 0;
				retval++;
				break ;
			}
			it_set++;
		}
		if (stop)
			return (retval);
		s1++;
	}
	return (retval);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			stop;
	size_t			size;
	int				len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	size = ft_strlen(s1);
	if (size == 0)
		return (ft_strdup(""));
	start = ft_find_start(s1, set);
	stop = ft_find_stop(s1, set);
	len = (int)size - (int)start - (int)stop;
	if (len < 0)
		return (ft_strdup(""));
	return (ft_substr(s1, start, size - start - stop));
}
