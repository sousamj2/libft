/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:40:35 by marisous          #+#    #+#             */
/*   Updated: 2026/11/07 16:35:05 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*retval;
	size_t	size;
	size_t	size_confirm;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	retval = malloc((size + 1) * sizeof(char));
	if (retval == NULL)
		return (NULL);
	size_confirm = ft_strlcpy(retval, s, size + 1);
	if (size != size_confirm)
	{
		free(retval);
		return (NULL);
	}
	return (retval);
}
