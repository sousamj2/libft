/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:43:11 by marisous          #+#    #+#             */
/*   Updated: 2026/11/04 10:45:23 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

static size_t	ft_next_c(const char *s, int c)
{
	size_t	next_c;
	size_t	size_str;

	next_c = 0;
	size_str = ft_strlen(s);
	while (*s != '\0')
	{
		if (*s == c)
			return (next_c);
		s++;
		next_c++;
	}
	return (size_str);
}

static size_t	ft_count_chars_c(char const *s, char c)
{
	size_t	retval;

	retval = 0;
	while (*s == c)
		s++;
	while (*s != '\0')
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			retval++;
		s++;
	}
	return (retval);
}

static char	**ft_allocate_string_array(char const *s, char c, size_t *nsplits)
{
	char	**retval;

	*nsplits = ft_count_chars_c(s, c) + 1;
	if (!ft_strlen(s))
		*nsplits = 0;
	retval = ft_calloc((*nsplits + 1), sizeof(char *));
	if (!retval)
		return (NULL);
	return (retval);
}

static void	*ft_release_mem(char **s, int isplit)
{
	while (isplit >= 0)
	{
		free(s[isplit]);
		isplit--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t			nsplits;
	size_t			isplit;
	size_t			next_c;
	char			**retval;

	retval = ft_allocate_string_array(s, c, &nsplits);
	if (!retval)
		return (NULL);
	isplit = 0;
	while (*s == c)
		s++;
	while (isplit < nsplits)
	{
		next_c = ft_next_c(s, c);
		retval[isplit] = ft_substr(s, 0, next_c);
		if (!retval[isplit])
			return (ft_release_mem(retval, isplit));
		s += next_c + 1;
		if (ft_strlen(retval[isplit]) > 0)
			isplit++;
		else
			free(retval[isplit]);
	}
	retval[isplit] = NULL;
	return (retval);
}
