/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:08:03 by marisous          #+#    #+#             */
/*   Updated: 2026/11/01 14:08:03 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*retval;
	unsigned int	index;

	retval = ft_strdup(s);
	if (retval == NULL)
		return (NULL);
	index = 0;
	while (*retval != '\0')
	{
		*retval = f(index, *retval);
		retval++;
		index++;
	}
	return (retval - index);
}
