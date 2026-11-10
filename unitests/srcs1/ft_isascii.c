/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:13:47 by marisous          #+#    #+#             */
/*   Updated: 2026/10/27 12:18:33 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <ctype.h>

#include "libft.h"

int	main(void)
{
	int	test;

	test = -10;
	while (test < 300)
	{
		if (ft_isascii(test) != !!isascii(test))
		{
			printf("ft_isascii FAIL: Value d[%d] c[%c] did not pass the test: \
%d vs %d (correct)\n", test, test, ft_isascii(test), !!isascii(test));
			return (1);
		}
		test++;
	}
	printf("ft_isascii: PASS\n");
	return (0);
}
