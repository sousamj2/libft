/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:43:11 by marisous          #+#    #+#             */
/*   Updated: 2026/11/05 18:10:24 by marisous         ###   ########.fr       */
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

static char	**ft_allocate_string_array(char *trim_s, char c, size_t *nsplits)
{
	char	**retval;
	size_t	size_trim;

	size_trim = ft_strlen(trim_s);
	*nsplits = 0;
	while (trim_s != NULL && *trim_s == c)
		trim_s++;
	while (trim_s != NULL && *trim_s != '\0')
	{
		if (*trim_s == c && *(trim_s + 1) != c && *(trim_s + 1) != '\0')
			(*nsplits)++;
		trim_s++;
	}
	(*nsplits)++;
	if (size_trim == 0)
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

static char	*ft_trim_char(char const *s, char c)
{
	char	*trim_s;
	char	cc[2];

	cc[0] = c;
	cc[1] = '\0';
	trim_s = ft_strtrim(s, cc);
	return (trim_s);
}

char	**ft_split(char const *s, char c)
{
	size_t	splits[2];
	size_t	next_c;
	char	**retval;
	char	*trim_s[2];

	trim_s[0] = ft_trim_char(s, c);
	trim_s[1] = trim_s[0];
	retval = ft_allocate_string_array(trim_s[1], c, &splits[0]);
	if (!retval)
		return (NULL);
	splits[1] = 0;
	while (splits[1] < splits[0])
	{
		next_c = ft_next_c(trim_s[1], c);
		retval[splits[1]] = ft_substr(trim_s[1], 0, next_c);
		if (!retval[splits[1]])
			return (ft_release_mem(retval, splits[1], trim_s[1]));
		trim_s[1] += next_c + 1;
		if (ft_strlen(retval[splits[1]]) > 1)
			retval[++splits[1]] = NULL;
		else
			free(retval[splits[1]]);
	}
	free(trim_s[0]);
	return (retval);
}
