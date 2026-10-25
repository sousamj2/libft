/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 19:28:46 by marisous          #+#    #+#             */
/*   Updated: 2026/10/25 21:56:07 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_rand(int limit)
{
	return (rand() % limit);
}

char	ft_rand_print(void)
{
	char	ret;

	ret = 0;
	while (1)
	{
		ret = ft_rand(256);
		if (ft_isprint(ret))
			break ;
	}
	return (ret);
}

char	*ft_rand_str(int size)
{
	char	*str;
	int		index;

	index = 0;
	str = malloc((size + 1) * sizeof(char));
	while (index < size)
	{
		str[index] = ft_rand_print();
		index++;
	}
	str[index] = '\0';
	return (str);
}
