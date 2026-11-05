/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 07:10:38 by marisous          #+#    #+#             */
/*   Updated: 2026/11/05 17:33:01 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>

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

	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1);
	start = ft_find_start(s1, set);
	stop = ft_find_stop(s1, set);
	len = (int)size - (int)start - (int)stop;
	if (len < 0)
		return (ft_strdup(""));
	return (ft_substr(s1, start, size - start - stop));
}
