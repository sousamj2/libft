/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 07:03:16 by marisous          #+#    #+#             */
/*   Updated: 2026/10/31 12:15:36 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*retval;
	size_t	size_alloc;

	if (!s1 || !s2)
		return (NULL);
	size_alloc = ft_strlen(s1) + ft_strlen(s2);
	retval = malloc((1 + size_alloc) * sizeof(char));
	if (!retval)
		return (NULL);
	while (*s1 != '\0')
	{
		*retval = *s1;
		retval++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*retval = *s2;
		retval++;
		s2++;
	}
	*retval = '\0';
	return (retval - size_alloc);
}
