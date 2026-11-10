/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:13:47 by marisous          #+#    #+#             */
/*   Updated: 2026/10/25 16:50:12 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <ctype.h>

#include "libft.h"

int	main(void)
{
	int	test;

	test = 0;
	while (test < 256)
	{
		if (!!ft_isprint(test) != !!isprint(test))
		{
			printf("ft_isprint FAIL: Value d[%d] c[%c] did not pass the test: \
%d vs %d (correct)\n", test, test, ft_isprint(test), !!isprint(test));
			return (1);
		}
		test++;
	}
	printf("ft_isprint: PASS\n");
	return (0);
}
