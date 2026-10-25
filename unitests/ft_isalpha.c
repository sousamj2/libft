/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:13:47 by marisous          #+#    #+#             */
/*   Updated: 2026/10/25 15:35:04 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include "libft.h"
#include <ctype.h>

int	main(void)
{
	int	test;

	test = 0;
	while (test < 256)
	{
		if (!!ft_isalpha(test) != !!isalpha(test))
		{
			printf("FAIL: Value d[%d] c[%c] did not pass the test:\
%d vs %d (correct)\n", test, test, ft_isalpha(test), !!isalpha(test));
			return (1);
		}
		test++;
	}
	printf("ft_isalpha: PASS\n");
	return (0);
}
