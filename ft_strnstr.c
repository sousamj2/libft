/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:16:38 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 12:01:48 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*lit_i;
	size_t	index;

	index = 0;
	lit_i = (char *) little;
	while (index <= len && *big != '\0')
	{
		if (*lit_i == *big)
			lit_i++;
		else
			lit_i = (char *) little;
		if (*lit_i == '\0')
			return ((char *)(big - ft_strlen(little) + 1));
		big++;
		index++;
	}
	return (NULL);
}
