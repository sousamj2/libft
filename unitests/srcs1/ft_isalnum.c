/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:13:47 by marisous          #+#    #+#             */
/*   Updated: 2026/10/25 16:49:51 by marisous         ###   ########.fr       */
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
		if (!!ft_isalnum(test) != !!isalnum(test))
		{
			printf("ft_isalnum FAIL: Value d[%d] c[%c] did not pass the test: \
%d vs %d (correct)\n", test, test, ft_isalnum(test), !!isalnum(test));
			return (1);
		}
		test++;
	}
	printf("ft_isalnum: PASS\n");
	return (0);
}
