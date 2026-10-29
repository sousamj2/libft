/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 22:26:55 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 19:54:13 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <time.h>

char	*ft_rand_mem(int size);
int		ft_rand(int limit);
char	ft_rand_memval(void);
int		ft_compare_memory(void *truth, void *test, size_t size_s, char *src);

int	main(void)
{
	char	*str[3];
	int		test_i;
	size_t	sizeof_mem[2];
	int		search;

	srand(time(0));
	test_i = 0;
	while (test_i < 1000)
	{
		sizeof_mem[0] = ft_rand(2000) + 1;
		sizeof_mem[1] = ft_rand(sizeof_mem[0]);
		search = ft_rand_memval();
		str[0] = ft_rand_mem(sizeof_mem[0]);
		str[1] = memchr(str[0], search, sizeof_mem[1]);
		str[2] = ft_memchr(str[0], search, sizeof_mem[1]);
		if (str[1] == NULL && str[2] == NULL)
		{
			free(str[0]);
			continue ;
		}
		if (str[1] != str[2])
		{
			printf("ft_memchr FAIL: ");
			printf("Memory did not pass the test for char c[%c]:\n", search);
			printf("[%p] (correct)\n[%p] (mine)\n", str[1], str[2]);
			free(str[0]);
			return (1);
		}
		test_i++;
		free(str[0]);
	}
	printf("ft_memchr: PASS\n");
	return (0);
}
