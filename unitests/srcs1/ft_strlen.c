/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:19:25 by marisous          #+#    #+#             */
/*   Updated: 2026/10/25 21:52:15 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <time.h>

char	*ft_rand_str(int size);
int		ft_rand(int limit);

int	main(void)
{
	char	*str;
	int		test_i;
	int		sizeof_str;

	srand(time(0));
	test_i = 0;
	while (test_i < 100)
	{
		sizeof_str = ft_rand(100);
		str = ft_rand_str(sizeof_str);
		if (ft_strlen(str) != strlen(str))
		{
			printf("ft_strlen FAIL: ");
			printf("String s[%s] did not pass the test: %ld vs %ld (correct)\n",
				str, ft_strlen(str), strlen(str));
			free(str);
			return (1);
		}
		test_i++;
		free(str);
	}
	printf("ft_strlen: PASS\n");
	return (0);
}
