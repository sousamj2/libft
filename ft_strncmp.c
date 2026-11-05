/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:17:37 by marisous          #+#    #+#             */
/*   Updated: 2026/11/05 11:50:17 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	index = 0;
	while ((*us1 != '\0' || *us2 != '\0') && index < n)
	{
		if (*us1 != *us2)
			return (*us1 - *us2);
		/* { */
		/* 	if (*us1 > *us2) return (1); else return (-1); */
		/* } */
		us1++;
		us2++;
		index++;
	}
	return (0);
}
