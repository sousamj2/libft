/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:16:38 by marisous          #+#    #+#             */
/*   Updated: 2026/11/07 23:21:25 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	match;
	size_t	size_little;

	if (big == NULL || little == NULL)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	size_little = ft_strlen(little);
	while (*big != '\0' && len >= size_little)
	{
		match = 0;
		while (*(little + match) != '\0')
		{
			if (*(little + match) == *(big + match))
				match++;
			else
				break ;
			if (*(little + match) == '\0')
				return ((char *) big);
		}
		big++;
		len--;
	}
	return (NULL);
}
