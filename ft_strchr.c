/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:01:50 by marisous          #+#    #+#             */
/*   Updated: 2026/11/07 16:34:09 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ichar;
	char	search;

	if (s == NULL)
		return (NULL);
	ichar = (char *) s;
	search = (char) c;
	if (search == '\0')
		return (ichar + ft_strlen(s));
	while (*ichar != '\0')
	{
		if (*ichar == search)
			return (ichar);
		ichar++;
	}
	return (NULL);
}
