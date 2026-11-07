/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:43:11 by marisous          #+#    #+#             */
/*   Updated: 2026/11/07 22:58:59 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts segments separated by delimiter c and allocates string array.
 *
 * @param trim_s Input string trimmed of leading/trailing delimiter characters.
 * @param c Delimiter character.
 * @param nsplits Pointer to size_t to receive total count of split substrings.
 * @return Allocated array of strings (NULL-terminated), or NULL on failure.
 */
static char		**ft_allocate_string_array(
					char **trim_s,
					char c,
					size_t *nsplits);

/**
 * @brief Frees partially allocated string array and trimmed string on error.
 *
 * @param s Array of allocated strings.
 * @param isplit Highest index allocated in s.
 * @param trim_s Dynamically allocated trimmed string to free.
 * @return Always returns NULL.
 */
static void		*ft_release_mem(char **s, size_t isplit, char *trim_s);
/**
 * @brief Helper that removes leading and trailing delimiter c from string s.
 *
 * @param s Input string.
 * @param c Delimiter character to trim.
 * @return Newly allocated trimmed string, or NULL on failure.
 */
static char		*ft_trim_char(char const *s, char c);

/**
 * @brief Finds the index of the next occurrence of character c in string s.
 *
 * @param s String to search.
 * @param c Delimiter character to find.
 * @return Index of delimiter character c, or length of string if not found.
 */
static size_t	ft_next_c(const char *s, int c);

static char	**ft_allocate_string_array(char **trim_s, char c, size_t *nsplits)
{
	char	**retval;

	*nsplits = 0;
	if (trim_s[1] == NULL)
		return (NULL);
	if (trim_s[1][0] == '\0')
	{
		free(trim_s[0]);
		trim_s[0] = NULL;
		return (ft_calloc(1, sizeof(char *)));
	}
	while (*trim_s[1] == c)
		trim_s[1]++;
	while (*trim_s[1] != '\0')
	{
		if (*trim_s[1] == c && *(trim_s[1] +1) != c && *(trim_s[1] +1) != '\0')
			(*nsplits)++;
		trim_s[1]++;
	}
	(*nsplits)++;
	retval = ft_calloc((*nsplits + 1), sizeof(char *));
	if (!retval)
		return (free(trim_s[0]), NULL);
	trim_s[1] = trim_s[0];
	return (retval);
}

static void	*ft_release_mem(char **s, size_t isplit, char *trim_s)
{
	isplit++;
	while (isplit > 0)
	{
		isplit--;
		free(s[isplit]);
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
	if (trim_s == NULL)
		return (NULL);
	return (trim_s);
}

static size_t	ft_next_c(const char *s, int c)
{
	size_t	next_c;
	size_t	size_str;

	next_c = 0;
	if (s == NULL)
		return (0);
	size_str = ft_strlen(s);
	while (*s != '\0')
	{
		if (s[1] == '\0')
			return (next_c + 1);
		if (*s == c)
			return (next_c);
		s++;
		next_c++;
	}
	return (size_str);
}

char	**ft_split(char const *s, char c)
{
	size_t	splits[2];
	size_t	next_c;
	char	**retval;
	char	*trim_s[2];

	trim_s[0] = ft_trim_char(s, c);
	trim_s[1] = trim_s[0];
	retval = ft_allocate_string_array(trim_s, c, &splits[0]);
	if (retval == NULL)
		return (NULL);
	splits[1] = 0;
	while (splits[1] < splits[0])
	{
		next_c = ft_next_c(trim_s[1], c);
		retval[splits[1]] = ft_substr(trim_s[1], 0, next_c);
		if (retval[splits[1]] == NULL)
			return (ft_release_mem(retval, splits[1], trim_s[0]));
		trim_s[1] += next_c + (trim_s[1][next_c] != '\0');
		if (retval[splits[1]][0] != '\0')
			splits[1]++;
		else
			free(retval[splits[1]]);
	}
	free(trim_s[0]);
	return (retval);
}
