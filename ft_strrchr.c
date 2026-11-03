/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:58:04 by marisous          #+#    #+#             */
/*   Updated: 2026/10/28 19:11:53 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ichar;

	ichar = (char *) s;
	while (*ichar != '\0')
		ichar++;
	while (ichar != s - 1)
	{
		if (*ichar == c)
			return (ichar);
		ichar--;
	}
	return (NULL);
}
