/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 07:10:38 by marisous          #+#    #+#             */
/*   Updated: 2026/10/31 11:51:52 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_set_size(char const *s1, char const *set)
{
	char	*start;
	size_t	count;
	int		skip;

	start = (char *)set;
	count = 0;
	while (*s1 != '\0')
	{
		set = start;
		skip = 0;
		while (*set != '\0')
		{
			if (*s1 == *set)
			{
				skip = 1;
				break ;
			}
			set++;
		}
		if (!skip)
			count++;
		s1++;
	}
	return (count + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*retval;
	char	*start;
	int		skip;

	if (!s1 || !set)
		return (NULL);
	retval = malloc(ft_count_set_size(s1, set) * sizeof(char));
	if (!retval)
		return (NULL);
	start = (char *) set;
	while (*s1 != '\0')
	{
		set = start;
		skip = 0;
		while (*set != '\0')
		{
			if (*s1 == *set)
			{
				skip = 1;
				break ;
			}
			set++;
		}
		if (!skip)
			*retval = *s1;
		s1++;
		retval++;
	}
	return (retval);
}
