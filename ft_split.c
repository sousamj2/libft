/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:43:11 by marisous          #+#    #+#             */
/*   Updated: 2026/11/05 02:37:51 by marisous         ###   ########.fr       */
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

static char	**ft_allocate_string_array(char *trim_s, char c, size_t *nsplits)
{
	char **retval;
	
	*nsplits = ft_count_chars_c(trim_s, c) + 1;
	if (!ft_strlen(trim_s))
		*nsplits = 0;
	retval = ft_calloc((*nsplits + 1), sizeof(char *));
	if (!retval)
		return (NULL);
	return (retval);
}

static void	*ft_release_mem(char **s, int isplit, char *trim_s)
{
	while (isplit >= 0)
	{
		free(s[isplit]);
		isplit--;
	}
	free(s);
	free(trim_s);	
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t			nsplits;
	size_t			isplit;
	size_t			next_c;
	char			**retval;

	char *trim_s[2];
	char cc[2];
	
	cc[0] = c;
	cc[1] = '\0';

	trim_s[1] = ft_strtrim(s, cc);
	trim_s[0] =  trim_s[1];
	
	retval = ft_allocate_string_array(trim_s[1], c, &nsplits);
	if (!retval)
		return (NULL);
	isplit = 0;
	while (isplit < nsplits)
	{
		next_c = ft_next_c(trim_s[1], c);
		retval[isplit] = ft_substr(trim_s[1], 0, next_c);
		if (!retval[isplit])
			return (ft_release_mem(retval, isplit, trim_s[1]));
		trim_s[1] += next_c + 1;
		if (ft_strlen(retval[isplit]) > 0)
			isplit++;
		else
			free(retval[isplit]);
	}
	retval[isplit] = NULL;
	free(trim_s[0]);
	return (retval);
}
