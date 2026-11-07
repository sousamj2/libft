/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:58:04 by marisous          #+#    #+#             */
/*   Updated: 2026/11/07 16:39:53 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
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
		ichar++;
	while (ichar != s - 1)
	{
		if (*ichar == search)
			return (ichar);
		ichar--;
	}
	return (NULL);
}
