/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 11:21:32 by marisous          #+#    #+#             */
/*   Updated: 2026/10/30 14:02:52 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(int argc, char *argv[])
{
	unsigned int	start;
	size_t			len;
	char			*s;
	char			*result;
	
    if (argc < 4)
    {
		printf("Not enough args to execute %s.\n",argv[0]);
		return (-1);
    }
	start = ft_atoi(argv[1]);
	len = ft_atoi(argv[2]);
	s = argv[3];
	result = ft_substr(s, start, len);
	printf("Result: [%s]\n", result);
	free(result);
	return (0);
}
