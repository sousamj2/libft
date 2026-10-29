/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 08:22:01 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 11:58:25 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char	*ft_rand_mem(int size);
int		ft_rand(int limit);

int	ft_same_memory(void *s1, size_t size)
{
	void	*s2;
	int		ret1;
	int		ret2;

	s2 = s1;
	ret1 = memcmp(s1, s2, size);
	ret2 = ft_memcmp(s1, s2, size);
	return (ret1 == ret2);
}

void	ft_printmem(void *s, size_t n)
{
	size_t			index;
	unsigned char	*c;

	index = 0;
	c = (unsigned char *) s;
	while (index < n)
	{
		printf("%x ", *c);
		index++;
		c++;
	}
	printf("\n");
}

int	ft_two_memories(void *s1, void *s2, size_t n)
{
	int	ret1;
	int	ret2;

	ret1 = memcmp(s1, s2, n);
	ret2 = ft_memcmp(s1, s2, n);
	if (ret1 != ret2)
	{
		printf("s1[%p]: ", s1);
		ft_printmem(s1, n);
		printf("s2[%p]: ", s2);
		ft_printmem(s2, n);
		printf("\n");
	}
	return (ret1 == ret2);
}

int	ft_random_mem(size_t n)
{
	void	*mem0;
	void	*mem1;
	int		ret[2];

	mem0 = ft_rand_mem(n);
	mem1 = ft_rand_mem(n);
	ret[0] = memcmp(mem0, mem1, n);
	ret[1] = ft_memcmp(mem0, mem1, n);
	if (ret[0] != ret[1])
	{
		printf("s1[%p]: ", mem0);
		ft_printmem(mem0, n);
		printf("s2[%p]: ", mem1);
		ft_printmem(mem1, n);
		printf("\n");
	}
	free(mem0);
	free(mem1);
	return (ret[0] == ret[1]);
}

int	main(void)
{
	void	*mem;
	int		test_i;
	int		sizeof_mem;

	srand(time(0));
	test_i = 0;
	while (test_i < 1000)
	{
		sizeof_mem = ft_rand(100);
		mem = ft_rand_mem(sizeof_mem);
		if (!ft_same_memory(mem, sizeof_mem)
			|| !ft_random_mem(2))
		{
			printf("ft_memcmp FAIL: ");
			printf("String s[%p] did not pass the test.\n", mem);
			free(mem);
			return (1);
		}
		test_i++;
		free(mem);
	}
	if (!ft_two_memories("aaa", "aaab", 5)
		|| !ft_two_memories("aaa", "aaab", 4)
		|| !ft_two_memories("aaa", "aaab", 3)
		|| !ft_two_memories("aab", "abb", 3)
		|| !ft_two_memories("aca", "aab", 3)
		|| !ft_two_memories("daa", "aaab", 3)
		|| !ft_two_memories("aaa", "aaab", 3)
		|| !ft_two_memories("", "aaab", 3)
		|| !ft_two_memories("aaa", "", 3)
		|| !ft_two_memories("aaa", "aaab", 0)
		|| !ft_two_memories("", "", 3))
		return (1);
	printf("ft_memcmp: PASS\n");
	return (0);
}
