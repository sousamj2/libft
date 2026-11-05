/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:16:38 by marisous          #+#    #+#             */
/*   Updated: 2026/11/05 00:07:47 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/bsd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*it_little;
	char	*it_big;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		it_little = (char *) little;
		it_big = (char *) big;
		while (*it_little != '\0')
		{
			if (*it_little == *it_big && len >= ft_strlen(little))
			{
				it_little++;
				it_big++;
			}
			else
				break ;
			if (*it_little == '\0')
				return ((char *) big);
		}
		big++;
		len--;		
	}
	return (NULL);
}
