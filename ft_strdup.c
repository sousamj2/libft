/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:40:35 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 22:10:59 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*retval;
	size_t	size;
	size_t	size_confirm;

	size = ft_strlen(s);
	retval = malloc(size * sizeof(char));
	if (!retval)
		return (NULL);
	size_confirm = ft_strlcpy(retval, s, size);
	if (size != size_confirm)
		return (NULL);
	return (retval);
}
