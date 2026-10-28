/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:01:50 by marisous          #+#    #+#             */
/*   Updated: 2026/10/28 17:32:21 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	char	*ichar;

	ichar = (char *) s;
	while (*ichar != '\0')
	{
		if (*ichar == c)
			return (ichar);
		ichar++;
	}
	return (NULL);
}
