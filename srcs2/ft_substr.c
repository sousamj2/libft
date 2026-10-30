/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 22:49:58 by marisous          #+#    #+#             */
/*   Updated: 2026/10/30 07:02:32 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*retval;
	unsigned int	index;

	if (!s)
		return (NULL);
	retval = malloc(len + 1);
	if (!retval)
		return (NULL);
	index = 0;	
	while (index < start)
	{
		index++;
		s++;
	}
	while (index < start + len)
	{
		retval[index - start] = s[index];
		index++;
		s++;
	}
	retval[index - start] = '\0';
	return (retval);
}	
